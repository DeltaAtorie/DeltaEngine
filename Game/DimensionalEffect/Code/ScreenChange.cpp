#include "stdafx.h"
#include "ScreenChange.h"
#include "DimensionalStorage/HeaderStorage.h"
bool ScreenChange::Start()
{
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	S_Element.P_Helper    = FindGO<Helper>("helper");
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
			M_Texture[0].ScreenChangeInit("Assets/Sprite/ScreenChange/ScreenChangeRight.DDS","Assets/Sprite/ScreenChange/ScreenChangeRightLoad.DDS", 1120.0f, 1080.0f);
			if (M_MoveState == SCREENCHANGE_IN)
			{
				M_Position[0] = M_PositionOut[0];
			}else {
				if (M_MoveState == SCREENCHANGE_OUT)
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
			M_Texture[1].ScreenChangeInit("Assets/Sprite/ScreenChange/ScreenChangeLeft.DDS","Assets/Sprite/ScreenChange/ScreenChangeLeftLoad.DDS" ,1120.0f, 1080.0f);
			if (M_MoveState == SCREENCHANGE_IN)
			{
				M_Position[1] = M_PositionOut[1];
			}else {
				if (M_MoveState == SCREENCHANGE_OUT)
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
	AlphaUpdate();

	if (M_MoveState == SCREENCHANGE_IN)
	{
		MoveIn();
	}else {
		if (M_MoveState == SCREENCHANGE_OUT)
		{
			MoveOut();
		}
	}
	
	M_Texture[0].Update();
	M_Texture[0].SetPositionX(M_Position[0]);
	M_Texture[0].ScreenChangeSet(M_ChangeState, M_Alpha);
	S_Element.P_Collision->DecisionSetPosition(M_Position[0].x,M_Position[0].y, COLLISION_SCREENRIGHT);

	M_Texture[1].Update();
	M_Texture[1].SetPositionX(M_Position[1]);
	M_Texture[1].ScreenChangeSet(M_ChangeState, M_Alpha);
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
			M_MoveState = SCREENCHANGE_NON;
			M_AlphaState = SCREENCHANGE_REVERSE;
			M_ChangeState = SCREENCHANGE_LOAD;
			M_Position[0] = M_PositionIn[0];
			M_Position[1] = M_PositionIn[1];
			M_MoveFlag   = false;
			S_Effect.P_Load = NewGO<Load>(5, "load");
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
			M_MoveState = SCREENCHANGE_NON;
			M_AlphaState = SCREENCHANGE_FORWARD;
			M_ChangeState = SCREENCHANGE_LOAD;
			M_Position[0] = M_PositionOut[0];
			M_Position[1] = M_PositionOut[1];
			M_MoveFlag    = false;
		}
	}
}
void ScreenChange::AlphaUpdate()
{
	if (M_AlphaState == SCREENCHANGE_FORWARD)
	{
		if (M_Alpha.x < 1.0f && M_Alpha.y > 0.0f)
		{
			S_Element.P_Helper->ForwardAlphaUpdate(M_Alpha, 1.0f);
		}else {
			M_AlphaState = SCREENCHANGE_REVERSE;
		}
	}else {
		if (M_AlphaState == SCREENCHANGE_REVERSE)
		{
			if (M_Alpha.x > 0.0f && M_Alpha.y < 1.0f)
			{
				S_Element.P_Helper->ReverseAlphaUpdate(M_Alpha, 1.0f);
			}else {
				M_AlphaState = SCREENCHANGE_FORWARD;
			}
		}
	}
}