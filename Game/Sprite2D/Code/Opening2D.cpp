#include "stdafx.h"
#include "Opening2D.h"
#include "Storage2D/Header2D.h"
bool Opening2D::Start()
{
	P_Sprite2D = FindGO<Sprite2D>("sprite2d");
	P_Sprite2D->Sprite2DFindGO();
	
	P_Data2D = FindGO<Data2D>("data2d");
	P_Data2D->Data2DFindGO();

	P_Operation = FindGO<Operation>("operation");
	P_Operation->OperationFindGO();

	M_Level2D.Init("Assets/Sprite/Opening2D/Opening2D.casl" , [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("GameTitle") == true)
		{
			M_GameTitleTexture.PercentInit("Assets/Sprite/Opening2D/GameTitleOff.DDS" , "Assets/Sprite/Opening2D/GameTitleOn.DDS" , 5 , 1920.0f , 1080.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_GameTitleTexture , &objData.position);
			return true;
		}
		if (objData.EqualObjectName("StartButton") == true)
		{
			M_StartButtonTexture.PercentInit("Assets/Sprite/Opening2D/StartButtonOff.DDS" , "Assets/Sprite/Opening2D/StartButtonOn.DDS" , 5 , 100.0f , 100.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_StartButtonTexture , &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(100 , 100 , objData.position.x , objData.position.y , "StartButton" , "Non");
			return true;
		}
		if (objData.EqualObjectName("OptionButton") == true)
		{
			M_OptionButtonTexture.PercentInit("Assets/Sprite/Opening2D/OptionButtonOff.DDS" , "Assets/Sprite/Opening2D/OptionButtonOn.DDS", 5 , 100.0f , 100.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_OptionButtonTexture, &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(100 , 100 , objData.position.x , objData.position.y , "OptionButton" , "Non");
			return true;
		}
		if (objData.EqualObjectName("PowerButton") == true)
		{
			M_PowerButtonTexture.PercentInit("Assets/Sprite/Opening2D/PowerButtonOff.DDS", "Assets/Sprite/Opening2D/PowerButtonOn.DDS", 5 , 100.0f, 100.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_PowerButtonTexture , &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(100 , 100 , objData.position.x , objData.position.y , "PowerButton" , "Non");
			return true;
		}
	});
	return true;
}
void Opening2D::Update()
{
	PowerUpdate();
	CollisionUpdate();

	SpriteRender* Sprite[4] = { &M_GameTitleTexture , &M_StartButtonTexture , &M_OptionButtonTexture , &M_PowerButtonTexture };
	for (int i = 0; i < sizeof(Sprite) / sizeof(Sprite[0]); i++)
	{Sprite[i]->PercentSet(S_Percent.GetPercent());}

	S_Percent.Update();
	S_CoolFlag.Update();
}
void Opening2D::Render(RenderContext& rc)
{
	SpriteRender* Sprite[4] = { &M_GameTitleTexture , &M_StartButtonTexture , &M_OptionButtonTexture , &M_PowerButtonTexture };
	for (int i = 0; i < sizeof(Sprite) / sizeof(Sprite[0]); i++)
	{P_Data2D->P_Helper2D->SpriteDraw(Sprite[i], rc);}
}

void Opening2D::PowerUpdate()
{
	if (M_PowerFlag)
	{
		S_Percent.Increase();
	}else {
		if (!M_PowerFlag)
		{
			S_Percent.Decrease();
			if (S_Percent.OverflowDown())
			{
				exit(1);
			}
		}
	}
}
void Opening2D::CollisionUpdate()
{
	if (P_Data2D->P_Collision2D->BodyAndBodyCollision("StartButton" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK))
	{
		if (S_CoolFlag.GetFlag() && M_PowerFlag && !P_Sprite2D->P_OptionSprite2D->GetPower())
		{
			P_Sprite2D->P_ScreenChange2D->ScreenCgangeIn();
		}
	}
	else {
		if (P_Data2D->P_Collision2D->BodyAndBodyCollision("OptionButton" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK))
		{
			if (S_CoolFlag.GetFlag() && M_PowerFlag)
			{
				P_Sprite2D->P_OptionSprite2D->PowerSwitch();
			}
		}
		else {
			if (P_Data2D->P_Collision2D->BodyAndBodyCollision("PowerButton" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK))
			{
				if (S_CoolFlag.GetFlag() && M_PowerFlag && !P_Sprite2D->P_OptionSprite2D->GetPower())
				{
					P_Data2D->P_Helper2D->FlagReverse(M_PowerFlag);
				}
			}
		}
	}
}