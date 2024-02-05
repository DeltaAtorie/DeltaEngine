#include "stdafx.h"
#include "ScreenChange.h"
#include "DimensionalStorage/HeaderStorage.h"
bool ScreenChange::Start()
{
	S_Effect.P_Load       = FindGO<Load>("load");
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	S_Element.P_Helper    = FindGO<Helper>("helper");
	M_Level2D.Init("Assets/Sprite/ScreenChange/ScreenChange.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("RightIn") == true)
		{
			M_PositionIn[SCREENCHANGE_RIGHT] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("RightOut") == true)
		{
			M_PositionOut[SCREENCHANGE_RIGHT] = objData.position;
			return true;
		}

		if (objData.EqualObjectName("LeftIn") == true)
		{
			M_PositionIn[SCREENCHANGE_LEFT] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("LeftOut") == true)
		{
			M_PositionOut[SCREENCHANGE_LEFT] = objData.position;
			return true;
		}
	});
	M_Level2D.Init("Assets/Sprite/ScreenChange/ScreenChange.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("Right") == true)
		{
			M_Texture[SCREENCHANGE_RIGHT].PercentInit("Assets/Sprite/ScreenChange/ScreenChangeRight.DDS","Assets/Sprite/ScreenChange/ScreenChangeRightLoad.DDS",0, 960.0f, 1080.0f);
			if (M_MoveState == SCREENCHANGE_IN)
			{
				M_Position[SCREENCHANGE_RIGHT] = M_PositionOut[SCREENCHANGE_RIGHT];
			}else {
				if (M_MoveState == SCREENCHANGE_OUT)
				{
					M_Position[SCREENCHANGE_RIGHT] = M_PositionIn[SCREENCHANGE_RIGHT];
				}
			}
			M_Texture[SCREENCHANGE_RIGHT].SetPosition(M_Position[SCREENCHANGE_RIGHT]);
			M_Texture[SCREENCHANGE_RIGHT].Update();

			S_Element.P_Collision->DecisionDataSet(960.0f , 1080.0f , M_Position[SCREENCHANGE_RIGHT].x    , M_Position[SCREENCHANGE_RIGHT].y    , COLLISION_SCREENRIGHT         , TAG_NON);
			S_Element.P_Collision->DecisionDataSet(960.0f , 1080.0f , M_PositionOut[SCREENCHANGE_RIGHT].x , M_PositionOut[SCREENCHANGE_RIGHT].y , COLLISION_SCREENRIGHTVALUEOUT , TAG_NON);
			return true;
		}

		if (objData.EqualObjectName("Left") == true)
		{
			M_Texture[SCREENCHANGE_LEFT].PercentInit("Assets/Sprite/ScreenChange/ScreenChangeLeft.DDS","Assets/Sprite/ScreenChange/ScreenChangeLeftLoad.DDS",1 ,960.0f, 1080.0f);
			if (M_MoveState == SCREENCHANGE_IN)
			{
				M_Position[SCREENCHANGE_LEFT]          = M_PositionOut[SCREENCHANGE_LEFT];
			}else {
				if (M_MoveState == SCREENCHANGE_OUT)
				{
					M_Position[SCREENCHANGE_LEFT]          = M_PositionIn[SCREENCHANGE_LEFT];
				}
			}
			M_Texture[SCREENCHANGE_LEFT].SetPosition(M_Position[SCREENCHANGE_LEFT]);
			M_Texture[SCREENCHANGE_LEFT].Update();

			S_Element.P_Collision->DecisionDataSet(960.0f , 1080.0f , M_Position[SCREENCHANGE_LEFT].x, M_Position[SCREENCHANGE_LEFT].y       , COLLISION_SCREENLEFT         , TAG_NON);
			S_Element.P_Collision->DecisionDataSet(960.0f , 1080.0f , M_PositionOut[SCREENCHANGE_LEFT].x, M_PositionOut[SCREENCHANGE_LEFT].y , COLLISION_SCREENLEFTVALUEOUT , TAG_NON);
			return true;
		}
	});
	return true;
}
void ScreenChange::Update()
{
	Move();

	S_Element.P_Helper->SpriteUpdate(M_Texture , M_Position , nullptr , sizeof(M_Texture)/sizeof(M_Texture[0]));
	M_Texture[SCREENCHANGE_RIGHT].PercentSet(S_Effect.P_Load->GetLoadPercent());
	M_Texture[SCREENCHANGE_LEFT].PercentSet(S_Effect.P_Load->GetLoadPercent());
	S_Element.P_Collision->DecisionSetPosition(M_Position[SCREENCHANGE_RIGHT].x , M_Position[SCREENCHANGE_RIGHT].y , COLLISION_SCREENRIGHT);
	S_Element.P_Collision->DecisionSetPosition(M_Position[SCREENCHANGE_LEFT].x  , M_Position[SCREENCHANGE_LEFT].y  , COLLISION_SCREENLEFT);
}
void ScreenChange::Render(RenderContext& rc)
{
	S_Element.P_Helper->SpriteDraw(M_Texture , rc , sizeof(M_Texture) / sizeof(M_Texture[0]));
}

void ScreenChange::Move()
{
	switch (M_MoveState)
	{
	case SCREENCHANGE_IN:
		MoveIn();
		break;
	case SCREENCHANGE_OUT:
		MoveOut();
		break;
	case SCREENCHANGE_NON:
		if (S_Effect.P_Load->GetLoadComplete() && g_pad[0]->IsTrigger(enButtonA))
		{MoveOut();}
		break;
	}
}
void ScreenChange::MoveIn()
{
	if (!S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_SCREENRIGHT , COLLISION_SCREENLEFT))
	{
		M_MoveState = SCREENCHANGE_IN;
		S_Element.P_Helper->ForwardAlphaUpdate(M_Position[SCREENCHANGE_LEFT].x           , M_Speed);
		S_Element.P_Helper->ReverseAlphaUpdate(M_Position[SCREENCHANGE_RIGHT].x          , M_Speed);

		S_Element.P_Helper->PositionOverflowUp(M_Position[SCREENCHANGE_LEFT].x             , M_PositionIn[SCREENCHANGE_LEFT].x);
		S_Element.P_Helper->PositionOverflowDown(M_Position[SCREENCHANGE_RIGHT].x          , M_PositionIn[SCREENCHANGE_RIGHT].x);
	}else {
		if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_SCREENRIGHT, COLLISION_SCREENLEFT))
		{
			M_MoveState   = SCREENCHANGE_NON;
			S_Effect.P_Load->SetLoadFile(0);
		}
	}
}
void ScreenChange::MoveOut()
{
	if (!S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENLEFTVALUEOUT , DIRECTION_LEFT , COLLISION_SCREENLEFT) && !S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENRIGHTVALUEOUT , DIRECTION_RIGHT , COLLISION_SCREENRIGHT))
	{
		M_MoveState = SCREENCHANGE_OUT;
		S_Element.P_Helper->ForwardAlphaUpdate(M_Position[SCREENCHANGE_RIGHT].x           , M_Speed);
		S_Element.P_Helper->ReverseAlphaUpdate(M_Position[SCREENCHANGE_LEFT].x            , M_Speed);

		S_Element.P_Helper->PositionOverflowUp(M_Position[SCREENCHANGE_RIGHT].x           , M_PositionOut[SCREENCHANGE_RIGHT].x);
		S_Element.P_Helper->PositionOverflowDown(M_Position[SCREENCHANGE_LEFT].x          , M_PositionOut[SCREENCHANGE_LEFT].x);
	}else {
		if (S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENLEFTVALUEOUT , DIRECTION_LEFT , COLLISION_SCREENLEFT) && S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENRIGHTVALUEOUT , DIRECTION_RIGHT , COLLISION_SCREENRIGHT))
		{
			M_MoveState   = SCREENCHANGE_NON;
		}
	}
}