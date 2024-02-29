#include "stdafx.h"
#include "Ui.h"
#include "Storage2D/Header2D.h"
bool Ui::Start()
{
	P_Data2D = FindGO<Data2D>("data2d");
	P_Data2D->Data2DFindGO();
	M_Level2D.Init("Assets/Sprite/Ui2D/Ui2D.casl", [&](Level2DRenderObjectData& objData)
	{
		//UI縁
		if (objData.EqualObjectName("UiFrame") == true)
		{
			M_UiFrameTexture.Init("Assets/Sprite/Ui2D/Frame.DDS", 1920.0f, 1080.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_UiFrameTexture, &objData.position);
			return true;
		}

		//占拠率
		if (objData.EqualObjectName("Percent") == true)
		{
			M_UiPercentTexture.Init("Assets/Sprite/Ui2D/Percent.DDS", 1000.0f, 55.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_UiPercentTexture, &objData.position);
			return true;
		}

		//ライフマーク
		if (objData.EqualObjectName("Life") == true)
		{
			M_UiLifeTexture.Init("Assets/Sprite/Ui2D/Life.DDS", 48.0f, 70.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_UiLifeTexture, &objData.position);
			return true;
		}

		//銃の種類
		if (objData.EqualObjectName("Handgun") == true)
		{
			M_UiGunTexture[0].Init("Assets/Sprite/Ui2D/Handgun.DDS", 150.0f, 85.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_UiGunTexture[0], &objData.position);
			return true;
		}
		if (objData.EqualObjectName("Shotgun") == true)
		{
			M_UiGunTexture[1].Init("Assets/Sprite/Ui2D/Shotgun.DDS", 150.0f, 85.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_UiGunTexture[1], &objData.position);
			return true;
		}
		if (objData.EqualObjectName("Machinegun") == true)
		{
			M_UiGunTexture[2].Init("Assets/Sprite/Ui2D/Machinegun.DDS", 150.0f, 85.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_UiGunTexture[2], &objData.position);
			return true;
		}

		//アイコン
		if (objData.EqualObjectName("PlayerIcon") == true)
		{
			M_UiIconTexture[0].Init("Assets/Sprite/Ui2D/PlayerIcon.DDS", 55.0f, 62.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_UiIconTexture[0], &objData.position);
			return true;
		}
		if (objData.EqualObjectName("EnemyIcon") == true)
		{
			M_UiIconTexture[1].Init("Assets/Sprite/Ui2D/EnemyIcon.DDS", 55.0f, 62.0f);
			P_Data2D->P_Helper2D->SpriteUpdate(&M_UiIconTexture[1], &objData.position);
			return true;
		}
			
	});
	return true;
}
void Ui::Update()
{

}
void Ui::Render(RenderContext& rc)
{
	SpriteRender* Sprite[8] =
	{
		&M_UiFrameTexture         ,
		&M_UiPercentTexture,
		&M_UiLifeTexture  ,
		&M_UiGunTexture[0]     ,
		&M_UiGunTexture[1]    ,
		&M_UiGunTexture[2]      ,
		&M_UiIconTexture[0]    ,
		&M_UiIconTexture[1]      
	};
	for (int i = 0; i < sizeof(Sprite) / sizeof(Sprite[0]); i++)
	{P_Data2D->P_Helper2D->SpriteDraw(Sprite[i], rc);}
}