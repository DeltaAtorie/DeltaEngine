#include "stdafx.h"
#include "ScreenChange.h"
#include "DimensionalStorage/HeaderStorage.h"
bool ScreenChange::Start()
{
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	M_Level2D.Init("Assets/Sprite/ScreenChange/ScreenChange.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("RightIn") == true)
		{
			M_PositionIn[0] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("RightOut") == true)
		{
			M_PositionOut[0] = objData.position;
			return true;
		}

		if (objData.EqualObjectName("LeftIn") == true)
		{
			M_PositionIn[1] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("LeftOut") == true)
		{
			M_PositionOut[1] = objData.position;
			return true;
		}
	});
	M_Level2D.Init("Assets/Sprite/ScreenChange/ScreenChange.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("Right") == true)
		{
			M_Texture[0].Init("Assets/Sprite/ScreenChange/ScreenChangeRight.DDS", 1120.0f, 1080.0f);
			if (M_MoveInFlag)
			{
				M_Position[0] = M_PositionOut[0];
			}else {
				if (M_MoveOutFlag)
				{
					M_Position[0] = M_PositionIn[0];
				}
			}
			M_Texture[0].SetPosition(M_Position[0]);
			M_Texture[0].Update();

			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_Position[0].x, M_Position[0].y, COLLISION_SCREENRIGHT, TAG_NON);
			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_PositionOut[0].x, M_PositionOut[0].y, COLLISION_SCREENRIGHTVALUE, TAG_NON);
			return true;
		}

		if (objData.EqualObjectName("Left") == true)
		{
			M_Texture[1].Init("Assets/Sprite/ScreenChange/ScreenChangeLeft.DDS", 1120.0f, 1080.0f);
			if (M_MoveInFlag)
			{
				M_Position[1] = M_PositionOut[1];
			}else {
				if (M_MoveOutFlag)
				{
					M_Position[1] = M_PositionIn[1];
				}
			}
			M_Texture[1].SetPosition(M_Position[1]);
			M_Texture[1].Update();

			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_Position[1].x, M_Position[1].y, COLLISION_SCREENLEFT, TAG_NON);
			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_PositionOut[1].x, M_PositionOut[1].y, COLLISION_SCREENLEFTVALUE, TAG_NON);
			return true;
		}
	});
	return true;
}
void ScreenChange::Update()
{
	if (M_MoveInFlag)
	{
		MoveIn();
	}else {
		if (M_MoveOutFlag)
		{
			MoveOut();
		}
	}
	
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

void ScreenChange::MoveIn()
{
	if (!S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_SCREENRIGHT, COLLISION_SCREENLEFT))
	{
		M_Position[0].x -= M_Speed * g_gameTime->GetFrameDeltaTime();
		M_Position[1].x += M_Speed * g_gameTime->GetFrameDeltaTime();
		M_MoveFlag = true;
	}else {
		if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_SCREENRIGHT, COLLISION_SCREENLEFT))
		{
			M_Position[0] = M_PositionIn[0];
			M_Position[1] = M_PositionIn[1];
			M_MoveFlag   = false;
			M_MoveInFlag = false;
		}
	}
}
void ScreenChange::MoveOut()
{
	if (!S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENLEFTVALUE,DIRECTION_LEFT,COLLISION_SCREENLEFT) && !S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENRIGHTVALUE, DIRECTION_RIGHT, COLLISION_SCREENRIGHT))
	{
		M_Position[0].x += M_Speed * g_gameTime->GetFrameDeltaTime();
		M_Position[1].x -= M_Speed * g_gameTime->GetFrameDeltaTime();
		M_MoveFlag = true;
	}else {
		if (S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENLEFTVALUE,DIRECTION_LEFT,COLLISION_SCREENLEFT) && S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENRIGHTVALUE, DIRECTION_RIGHT, COLLISION_SCREENRIGHT))
		{
			M_Position[0] = M_PositionOut[0];
			M_Position[1] = M_PositionOut[1];
			M_MoveFlag    = false;
			M_MoveOutFlag = false;
		}
	}
}