#include "stdafx.h"
#include "Load.h"
#include "DimensionalStorage/HeaderStorage.h"
bool Load::Start()
{
	S_Effect.P_Fade = FindGO<Fade>("fade");
	M_Level2D.Init("Assets/Sprite/Load/Load.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("Logo") == true)
		{
			M_LoadTexture.PercentInit("Assets/Sprite/Load/Logo.DDS", "Assets/Sprite/Load/LogoOn.DDS", 3, 450.0f, 450.0f);
			return true;
		}
		if (objData.EqualObjectName("100") == true)
		{
			M_LoadCountTexture[0].CurrentTimeInit("Assets/Sprite/Count/WallPaper.DDS", 80.0f, 80.0f);
			M_LoadCountTexture[0].SetPosition(objData.position);
			M_LoadCountTexture[0].Update();
			return true;
		}
		if (objData.EqualObjectName("10") == true)
		{
			M_LoadCountTexture[1].CurrentTimeInit("Assets/Sprite/Count/WallPaper.DDS", 80.0f, 80.0f);
			M_LoadCountTexture[1].SetPosition(objData.position);
			M_LoadCountTexture[1].Update();
			return true;
		}
		if (objData.EqualObjectName("1") == true)
		{
			M_LoadCountTexture[2].CurrentTimeInit("Assets/Sprite/Count/WallPaper.DDS", 80.0f, 80.0f);
			M_LoadCountTexture[2].SetPosition(objData.position);
			M_LoadCountTexture[2].Update();
			return true;
		}
	});
	S_Effect.P_Fade->StartFadeOut();
	return true;
}
void Load::Update()
{
	M_LoadPercent.x -= 0.8 * g_gameTime->GetFrameDeltaTime();
	M_LoadPercent.y += 0.8 * g_gameTime->GetFrameDeltaTime();
	M_LoadTexture.SetMulColor({ 1.0f, 1.0f, 1.0f, S_Effect.P_Fade->GetCurrentAlpha()});
	M_LoadTexture.PercentSet(M_LoadPercent);
	M_LoadTexture.Update();

	int Percent = (int)(M_LoadPercent.y * 100);
	M_LoadCountTexture[0].CurrentTimeSet((int)(Percent / 100));
	M_LoadCountTexture[1].CurrentTimeSet((int)(Percent % 100)/10);
	M_LoadCountTexture[2].CurrentTimeSet((int)(Percent % 100)%10);
}
void Load::Render(RenderContext& rc)
{
	M_LoadTexture.Draw(rc);
	M_LoadCountTexture[0].Draw(rc);
	M_LoadCountTexture[1].Draw(rc);
	M_LoadCountTexture[2].Draw(rc);
}