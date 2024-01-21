#include "stdafx.h"
#include "ScreenChange.h"
#include "DimensionalStorage/HeaderStorage.h"
bool ScreenChange::Start()
{
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	M_Level2D.Init("Assets/Sprite/ScreenChange/ScreenChange.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("Right") == true)
		{
			objData.position.x += 1120.0f;
			M_Texture[0].Init("Assets/Sprite/ScreenChange/ScreenChangeRight.DDS", 1120.0f, 1080.0f);
			M_Texture[0].SetPosition(objData.position);
			M_Texture[0].Update();

			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, objData.position.x, objData.position.y, COLLISION_SCREENRIGHT, TAG_NON);
			M_Position[0] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("Left") == true)
		{
			objData.position.x -= 1120.0f;
			M_Texture[1].Init("Assets/Sprite/ScreenChange/ScreenChangeLeft.DDS", 1120.0f, 1080.0f);
			M_Texture[1].SetPosition(objData.position);
			M_Texture[1].Update();

			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, objData.position.x, objData.position.y, COLLISION_SCREENLEFT, TAG_NON);
			M_Position[1] = objData.position;
			return true;
		}
	});
	return true;
}
void ScreenChange::Update()
{
	Move();
	M_Texture[0].Update();
	M_Texture[0].SetPositionX(M_Position[0]);
	S_Element.P_Collision->DecisionSetPosition(M_Position[0].x,M_Position[0].y, COLLISION_SCREENRIGHT);
	M_Texture[1].Update();
	M_Texture[1].SetPositionX(M_Position[1]);
	S_Element.P_Collision->DecisionSetPosition(M_Position[1].x, M_Position[1].y, COLLISION_SCREENLEFT);
}
void ScreenChange::Render(RenderContext& rc)
{
	M_Texture[0].Draw(rc);
	M_Texture[1].Draw(rc);
}

void ScreenChange::Move()
{
	if (!S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_SCREENRIGHT, COLLISION_SCREENLEFT))
	{
		M_Position[0].x -= M_Speed * g_gameTime->GetFrameDeltaTime();
		M_Position[1].x += M_Speed * g_gameTime->GetFrameDeltaTime();
	}else {
		if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_SCREENRIGHT, COLLISION_SCREENLEFT))
		{
			M_Position[0].x = 400.0f;
			M_Position[1].x = -400.0f;
		}
	}
}