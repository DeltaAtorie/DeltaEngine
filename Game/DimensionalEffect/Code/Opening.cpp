#include "stdafx.h"
#include "Opening.h"

#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalStorage/NumberStorage.h"
#include "Operation/Operation.h"
Opening::Opening()
{
	M_Level2D.Init("Assets/Sprite/Opening/Opening.casl", [&](Level2DRenderObjectData& objData)	
	{
		if (objData.EqualObjectName("WallPaper") == true)
		{
			M_WallTexture.FadeInit("Assets/Sprite/Opening/WallPaper.DDS","Assets/Sprite/Opening/WallPaperOn.DDS", &M_Alfha, 1920.0f, 1080.0f);
			M_WallPosition = objData.position;
			M_WallTexture.SetPosition(M_WallPosition);
			M_WallTexture.Update();
			return true;
		}
		if (objData.EqualObjectName("Switch") == true)
		{
			M_ButtonTexture.FadeInit("Assets/Sprite/Opening/Switch.DDS", "Assets/Sprite/Opening/SwitchOn.DDS",&M_Alfha, 75.0f, 75.0f);
			M_ButtonPosition = objData.position;
			M_ButtonTexture.SetPosition(M_ButtonPosition);
			M_ButtonTexture.Update();
			return true;
		}
	});
}
bool Opening::Start()
{
	S_Operation.P_Mouse = FindGO<Mouse>("mouse");
	S_Effect.P_Sound = FindGO<Sound>("sound");
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	S_Element.P_Collision->DecisionDataSet(75, 75, M_ButtonPosition.x, M_ButtonPosition.y, COLLISION_BUTTON, TAG_NON);
	return true;
}
void Opening::Update()
{
	if (!M_Flag)
	{
		if (!S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_MOUSE, COLLISION_BUTTON))
		{
			if (M_Alfha.y > 0.0f && M_Alfha.x < 1.0f)
			{
				M_Alfha.x += M_AlfhaSpeed * g_gameTime->GetFrameDeltaTime();
				M_Alfha.y -= M_AlfhaSpeed * g_gameTime->GetFrameDeltaTime();
			}
		}
	}else {
		if (M_Flag)
		{
			if (M_Alfha.x > 0.0f && M_Alfha.y < 1.0f)
			{
				M_Alfha.x -= M_AlfhaSpeed * g_gameTime->GetFrameDeltaTime();
				M_Alfha.y += M_AlfhaSpeed * g_gameTime->GetFrameDeltaTime();
			}
		}
	}

	if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_MOUSE, COLLISION_BUTTON))
	{
		if (S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON) && !M_Flag)
		{
			M_Flag = true;
		}
	}
}
void Opening::Render(RenderContext& rc)
{
	M_WallTexture.Draw(rc);
	M_ButtonTexture.Draw(rc);
}