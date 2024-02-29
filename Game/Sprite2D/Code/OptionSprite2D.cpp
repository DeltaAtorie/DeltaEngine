#include "stdafx.h"
#include "OptionSprite2D.h"
#include "Storage2D/Header2D.h"
bool OptionSprite2D::Start()
{
	P_Data2D = FindGO<Data2D>("data2d");
	P_Data2D->Data2DFindGO();
	P_Operation = FindGO<Operation>("operation");
	P_Operation->OperationFindGO();

	M_Level2D.Init("Assets/Sprite/OptionSprite2D/OptionSprite2D.casl" , [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("OptionFrame") == true)
		{
			M_OptionFrameTexture.Init("Assets/Sprite/OptionSprite2D/OptionFrame.DDS" , 400.0f , 800.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_OptionFrameTexture , &objData.position);
			return true;
		}

		if (objData.EqualObjectName("Bgm") == true)
		{
			M_BgmTexture[OPTION_NAME].Init("Assets/Sprite/OptionSprite2D/Bgm.DDS", 100.0f, 40.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_BgmTexture[OPTION_NAME], &objData.position);
			return true;
		}
		if (objData.EqualObjectName("BgmMemory") == true)
		{
			M_BgmTexture[OPTION_MEMORY].PercentInit("Assets/Sprite/OptionSprite2D/Memory.DDS" , "Assets/Sprite/OptionSprite2D/MemoryOn.DDS" , 1 , 172.0f , 50.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_BgmTexture[OPTION_MEMORY] , &objData.position);
			return true;
		}
		if (objData.EqualObjectName("Bgm+") == true)
		{
			M_BgmTexture[OPTION_PLUS].Init("Assets/Sprite/OptionSprite2D/PlusButton.DDS" , 60.0f , 60.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_BgmTexture[OPTION_PLUS] , &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(60.0f , 60.0f , objData.position.x, objData.position.y , "Bgm+Button" , "Non");
			return true;
		}
		if (objData.EqualObjectName("Bgm-") == true)
		{
			M_BgmTexture[OPTION_MINUS].Init("Assets/Sprite/OptionSprite2D/MinusButton.DDS" , 60.0f , 60.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_BgmTexture[OPTION_MINUS] , &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(60.0f , 60.0f , objData.position.x , objData.position.y , "Bgm-Button" , "Non");
			return true;
		}

		if (objData.EqualObjectName("Se") == true)
		{
			M_SeTexture[OPTION_NAME].Init("Assets/Sprite/OptionSprite2D/Se.DDS", 100.0f, 40.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_SeTexture[OPTION_NAME], &objData.position);
			return true;
		}
		if (objData.EqualObjectName("SeMemory") == true)
		{
			M_SeTexture[OPTION_MEMORY].PercentInit("Assets/Sprite/OptionSprite2D/Memory.DDS" , "Assets/Sprite/OptionSprite2D/MemoryOn.DDS" , 1 , 172.0f , 50.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_SeTexture[OPTION_MEMORY] , &objData.position);
			return true;
		}
		if (objData.EqualObjectName("Se+") == true)
		{
			M_SeTexture[OPTION_PLUS].Init("Assets/Sprite/OptionSprite2D/PlusButton.DDS" , 60.0f , 60.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_SeTexture[OPTION_PLUS] , &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(60.0f , 60.0f , objData.position.x , objData.position.y , "Se+Button" , "Non");
			return true;
		}
		if (objData.EqualObjectName("Se-") == true)
		{
			M_SeTexture[OPTION_MINUS].Init("Assets/Sprite/OptionSprite2D/MinusButton.DDS" , 60.0f , 60.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_SeTexture[OPTION_MINUS] , &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(60.0f , 60.0f , objData.position.x , objData.position.y , "Se-Button" , "Non");
			return true;
		}

		if (objData.EqualObjectName("Ui") == true)
		{
			M_AlphaTexture[OPTION_NAME].Init("Assets/Sprite/OptionSprite2D/Ui.DDS", 100.0f, 40.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_AlphaTexture[OPTION_NAME], &objData.position);
			return true;
		}
		if (objData.EqualObjectName("AlphaMemory") == true)
		{
			M_AlphaTexture[OPTION_MEMORY].PercentInit("Assets/Sprite/OptionSprite2D/Memory.DDS" , "Assets/Sprite/OptionSprite2D/MemoryOn.DDS" , 1 , 172.0f , 50.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_AlphaTexture[OPTION_MEMORY] , &objData.position);
			return true;
		}
		if (objData.EqualObjectName("Alpha+") == true)
		{
			M_AlphaTexture[OPTION_PLUS].Init("Assets/Sprite/OptionSprite2D/PlusButton.DDS" , 60.0f , 60.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_AlphaTexture[OPTION_PLUS] , &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(60.0f , 60.0f , objData.position.x, objData.position.y , "Alpha+Button" , "Non");
			return true;
		}
		if (objData.EqualObjectName("Alpha-") == true)
		{
			M_AlphaTexture[OPTION_MINUS].Init("Assets/Sprite/OptionSprite2D/MinusButton.DDS", 60.0f, 60.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_AlphaTexture[OPTION_MINUS] , &objData.position);
			P_Data2D->P_Collision2D->BodyDataSet(60.0f , 60.0f , objData.position.x , objData.position.y , "Alpha-Button" , "Non");
			return true;
		}
	});
	return true;
}
void OptionSprite2D::Update()
{
	Button();
	Power();

	//α値
	SpriteRender* Sprite1[13] =
	{
		&M_OptionFrameTexture          ,
		&M_BgmTexture[OPTION_NAME]     ,
		&M_BgmTexture[OPTION_MEMORY]   ,
		&M_BgmTexture[OPTION_PLUS]     ,
		&M_BgmTexture[OPTION_MINUS]    ,
		&M_SeTexture[OPTION_NAME]      ,
		&M_SeTexture[OPTION_MEMORY]    ,
		&M_SeTexture[OPTION_PLUS]      ,
		&M_SeTexture[OPTION_MINUS]     ,
		&M_AlphaTexture[OPTION_NAME]   ,
		&M_AlphaTexture[OPTION_MEMORY] ,
		&M_AlphaTexture[OPTION_PLUS]   ,
		&M_AlphaTexture[OPTION_MINUS]
	};
	Vector4 M_Color = { 1.0f , 1.0f , 1.0f , S_AlphaPercent.GetPercent() };
	for (int i = 0 ; i < sizeof(Sprite1) / sizeof(Sprite1[0]) ; i++)
	{P_Data2D->P_Helper2D->SpriteUpdate(Sprite1[i], &M_Color);}

	//パーセント
	SpriteRender* Sprite2[3] =
	{
		&M_BgmTexture[OPTION_MEMORY]   ,
		&M_SeTexture[OPTION_MEMORY]    ,
		&M_AlphaTexture[OPTION_MEMORY]
	};
	float Percent[3] =
	{
		S_BgmPercent.GetPercent()     ,
		S_SePercent.GetPercent()      ,
		S_UiPercent.GetPercent()
	};
	for (int i = 0 ; i < sizeof(Sprite2) / sizeof(Sprite2[0]) ; i++)
	{Sprite2[i]->PercentSet(Percent[i]);}

	S_BgmPercent.Update();
	S_SePercent.Update();
	S_UiPercent.Update();
	S_AlphaPercent.Update();
	S_CoolFlag.Update();
}
void OptionSprite2D::Render(RenderContext& rc)
{
	SpriteRender* Sprite1[13] =
	{
		&M_OptionFrameTexture          ,
		&M_BgmTexture[OPTION_NAME]     ,
		&M_BgmTexture[OPTION_MEMORY]   ,
		&M_BgmTexture[OPTION_PLUS]     ,
		&M_BgmTexture[OPTION_MINUS]    ,
		&M_SeTexture[OPTION_NAME]      ,
		&M_SeTexture[OPTION_MEMORY]    ,
		&M_SeTexture[OPTION_PLUS]      ,
		&M_SeTexture[OPTION_MINUS]     ,
		&M_AlphaTexture[OPTION_NAME]   ,
		&M_AlphaTexture[OPTION_MEMORY] ,
		&M_AlphaTexture[OPTION_PLUS]   ,
		&M_AlphaTexture[OPTION_MINUS]
	};
	for (int i = 0 ; i < sizeof(Sprite1) / sizeof(Sprite1[0]) ; i++)
	{P_Data2D->P_Helper2D->SpriteDraw(Sprite1[i], rc);}
}

void OptionSprite2D::Button()
{
	PlusButton();
	MinusButton();
}
void OptionSprite2D::PlusButton()
{
	if (P_Data2D->P_Collision2D->BodyAndBodyCollision("Bgm+Button" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK) && M_PowerFlag)
	{
		if (S_CoolFlag.GetFlag())
		{
			S_BgmPercent.Increment();
		}
	}else {
		if (P_Data2D->P_Collision2D->BodyAndBodyCollision("Se+Button" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK) && M_PowerFlag)
		{
			if (S_CoolFlag.GetFlag())
			{
				S_SePercent.Increment();
			}
		}else {
			if (P_Data2D->P_Collision2D->BodyAndBodyCollision("Alpha+Button" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK) && M_PowerFlag)
			{
				if (S_CoolFlag.GetFlag())
				{
					S_UiPercent.Increment();
				}
			}
		}
	}
}
void OptionSprite2D::MinusButton()
{
	if (P_Data2D->P_Collision2D->BodyAndBodyCollision("Bgm-Button" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK) && M_PowerFlag)
	{
		if (S_CoolFlag.GetFlag())
		{
			S_BgmPercent.Decrement();
		}
	}else {
		if (P_Data2D->P_Collision2D->BodyAndBodyCollision("Se-Button" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK) && M_PowerFlag)
		{
			if (S_CoolFlag.GetFlag())
			{
				S_SePercent.Decrement();
			}
		}else {
			if (P_Data2D->P_Collision2D->BodyAndBodyCollision("Alpha-Button" , "Mouse") && P_Operation->P_Mouse->GetMouseFlag(MOUSE_LEFTCLICK) && M_PowerFlag)
			{
				if (S_CoolFlag.GetFlag())
				{
					S_UiPercent.Decrement();
				}
			}
		}
	}
}

void OptionSprite2D::Power()
{
	if (M_PowerFlag)
	{
		S_AlphaPercent.Increase();
	}else {
		if (!M_PowerFlag)
		{
			S_AlphaPercent.Decrease();
		}
	}
}
void OptionSprite2D::PowerSwitch()
{P_Data2D->P_Helper2D->FlagReverse(M_PowerFlag);}