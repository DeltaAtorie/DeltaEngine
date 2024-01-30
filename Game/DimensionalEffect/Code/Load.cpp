#include "stdafx.h"
#include "Load.h"
#include "DimensionalStorage/HeaderStorage.h"
bool Load::Start()
{
	S_Effect.P_Fade = FindGO<Fade>("fade");
	S_Element.P_Helper = FindGO<Helper>("helper");
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
		if (objData.EqualObjectName("%") == true)
		{
			M_LoadSymbolTexture.SymbolInit("Assets/Sprite/Count/WallPaper.DDS",SYMBOL_PERCENT, 80.0f, 80.0f);
			M_LoadSymbolTexture.SetPosition(objData.position);
			M_LoadSymbolTexture.Update();
			return true;
		}
	});
	S_Effect.P_Fade->StartFadeOut();
	SetLoadFile(LOADFILE_GAME);
	return true;
}
void Load::Update()
{
	if (!S_Effect.P_Fade->IsFade())
	{
		switch (M_LoadState)
		{
		case LOADSTATE_LOADING:
			Loading();
			break;
		case LOADSTATE_LOADCOMPLETE:
			LoadComplete();
			break;
		}

		int Percent = (int)(M_LoadPercent.y * 100);
		M_LoadCountTexture[0].CurrentTimeSet((int)(Percent / 100));
		M_LoadCountTexture[1].CurrentTimeSet((int)(Percent % 100) / 10);
		M_LoadCountTexture[2].CurrentTimeSet((int)(Percent % 100) % 10);
		M_LoadTexture.PercentSet(M_LoadPercent);
	}
	S_Element.P_Helper->SpriteColorUpdate(&M_LoadTexture, { 1.0f, 1.0f, 1.0f, S_Effect.P_Fade->GetCurrentAlpha() });
	S_Element.P_Helper->SpriteColorUpdate(M_LoadCountTexture, { 1.0f, 1.0f, 1.0f, S_Effect.P_Fade->GetCurrentAlpha() }, sizeof(M_LoadCountTexture) / sizeof(M_LoadCountTexture[0]));
	S_Element.P_Helper->SpriteColorUpdate(&M_LoadSymbolTexture, { 1.0f, 1.0f, 1.0f, S_Effect.P_Fade->GetCurrentAlpha() });
}
void Load::Render(RenderContext& rc)
{
	S_Element.P_Helper->SpriteRender(&M_LoadTexture       , rc);
	S_Element.P_Helper->SpriteRender(M_LoadCountTexture   , rc , sizeof(M_LoadCountTexture) / sizeof(M_LoadCountTexture[0]));
	S_Element.P_Helper->SpriteRender(&M_LoadSymbolTexture , rc);
}

void Load::Loading()
{
	if (M_LoadPercent.x > 0.0f && M_LoadPercent.y < 1.0f)
	{
		S_Element.P_Helper->ReverseAlphaUpdate(M_LoadPercent, 0.8);
	}else {
		M_LoadPercent = { 0.0f,1.0f };
		M_LoadState = LOADSTATE_LOADCOMPLETE;
	}
}
void Load::LoadComplete()
{
	//S_Effect.P_Fade->StartFadeIn();
	//DeleteGO(this);
}