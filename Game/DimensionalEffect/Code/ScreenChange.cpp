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
		if (objData.EqualObjectName("RightCollisionIn") == true)
		{
			M_PositionCollisionIn[0] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("RightCollisionOut") == true)
		{
			M_PositionCollisionOut[0] = objData.position;
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
		if (objData.EqualObjectName("LeftCollisionIn") == true)
		{
			M_PositionCollisionIn[1] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("LeftCollisionOut") == true)
		{
			M_PositionCollisionOut[1] = objData.position;
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
				M_PositionCollision[0] = M_PositionCollisionOut[0];
			}else {
				if (M_MoveState == SCREENCHANGE_OUT)
				{
					M_Position[0] = M_PositionIn[0];
					M_PositionCollision[0] = M_PositionCollisionIn[0];
				}
			}
			M_Texture[0].SetPosition(M_Position[0]);
			M_Texture[0].Update();

			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_PositionCollision[0].x, M_PositionCollision[0].y, COLLISION_SCREENRIGHT, TAG_NON);
			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_PositionCollisionIn[0].x, M_PositionCollisionIn[0].y, COLLISION_SCREENRIGHT, TAG_NON);
			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_PositionCollisionOut[0].x, M_PositionCollisionOut[0].y, COLLISION_SCREENRIGHTVALUEOUT, TAG_NON);
			return true;
		}

		if (objData.EqualObjectName("Left") == true)
		{
			M_Texture[1].ScreenChangeInit("Assets/Sprite/ScreenChange/ScreenChangeLeft.DDS","Assets/Sprite/ScreenChange/ScreenChangeLeftLoad.DDS" ,1120.0f, 1080.0f);
			if (M_MoveState == SCREENCHANGE_IN)
			{
				M_Position[1] = M_PositionOut[1];
				M_PositionCollision[1] = M_PositionCollisionOut[1];
			}else {
				if (M_MoveState == SCREENCHANGE_OUT)
				{
					M_Position[1] = M_PositionIn[1];
					M_PositionCollision[1] = M_PositionCollisionIn[1];
				}
			}
			M_Texture[1].SetPosition(M_Position[1]);
			M_Texture[1].Update();

			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_PositionCollision[1].x, M_PositionCollision[1].y, COLLISION_SCREENLEFT, TAG_NON);
			S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, M_PositionCollisionOut[1].x, M_PositionCollisionOut[1].y, COLLISION_SCREENLEFTVALUEOUT, TAG_NON);
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
	S_Element.P_Collision->DecisionSetPosition(M_PositionCollision[0].x,M_PositionCollision[0].y, COLLISION_SCREENRIGHT);

	M_Texture[1].Update();
	M_Texture[1].SetPositionX(M_Position[1]);
	M_Texture[1].ScreenChangeSet(M_ChangeState, M_Alpha);
	S_Element.P_Collision->DecisionSetPosition(M_PositionCollision[1].x, M_PositionCollision[1].y, COLLISION_SCREENLEFT);

	swprintf_s(M_PX, 256, L"PositionLeftX:%f", M_Position[0].x);
	PositionX.SetText(M_PX);
	PositionX.SetPosition({ 300.0f,500.0f,0.0f });
	PositionX.SetScale(1.0f);

	swprintf_s(M_PY, 256, L"PositionRightX:%f", M_Position[1].x);
	PositionY.SetText(M_PY);
	PositionY.SetPosition({ 300.0f,400.0f,0.0f });
	PositionY.SetScale(1.0f);

	swprintf_s(M_CX, 256, L"CollisionLeftX:%f", M_PositionCollision[0].x);
	CollisionX.SetText(M_CX);
	CollisionX.SetPosition({ 300.0f,300.0f,0.0f });
	CollisionX.SetScale(1.0f);

	if (M_MoveState == SCREENCHANGE_IN)
	{
		swprintf_s(M_CY, 256, L"MoveIn");
		CollisionY.SetText(M_CY);
		CollisionY.SetPosition({ 300.0f,200.0f,0.0f });
		CollisionY.SetScale(1.0f);
	}else {
		if (M_MoveState == SCREENCHANGE_OUT)
		{
			swprintf_s(M_CY, 256, L"MoveOut");
			CollisionY.SetText(M_CY);
			CollisionY.SetPosition({ 300.0f,200.0f,0.0f });
			CollisionY.SetScale(1.0f);
		}else {
			if (M_MoveState == SCREENCHANGE_NON)
			{
				swprintf_s(M_CY, 256, L"MoveNon");
				CollisionY.SetText(M_CY);
				CollisionY.SetPosition({ 300.0f,200.0f,0.0f });
				CollisionY.SetScale(1.0f);
			}
		}
	}
	

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		M_MoveState = SCREENCHANGE_NON;
	}
	if (g_pad[0]->IsTrigger(enButtonB))
	{
		M_MoveState = SCREENCHANGE_IN;
	}
}
void ScreenChange::Render(RenderContext& rc)
{
	M_Texture[0].Draw(rc);
	M_Texture[1].Draw(rc);

	PositionX.Draw(rc);
	PositionY.Draw(rc);
	CollisionX.Draw(rc);
	CollisionY.Draw(rc);
}

void ScreenChange::MoveIn()
{
	if (!S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_SCREENRIGHT, COLLISION_SCREENLEFT))
	{
		M_Position[0].x -= M_Speed * g_gameTime->GetFrameDeltaTime();
		M_Position[1].x += M_Speed * g_gameTime->GetFrameDeltaTime();
		M_PositionCollision[0].x -= M_Speed * g_gameTime->GetFrameDeltaTime();
		M_PositionCollision[1].x += M_Speed * g_gameTime->GetFrameDeltaTime();
		M_MoveFlag = true;
	}else {
		if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_SCREENRIGHT, COLLISION_SCREENLEFT))
		{
			M_MoveState = SCREENCHANGE_NON;
			M_AlphaState = SCREENCHANGE_REVERSE;
			M_ChangeState = SCREENCHANGE_LOAD;
			M_Position[0] = M_PositionIn[0];
			M_Position[1] = M_PositionIn[1];
			M_PositionCollision[0] = M_PositionCollisionIn[0];
			M_PositionCollision[1] = M_PositionCollisionIn[1];
			M_MoveFlag   = false;
			S_Effect.P_Load = NewGO<Load>(5, "load");
		}
	}
}
void ScreenChange::MoveOut()
{
	if (!S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENLEFTVALUEOUT,DIRECTION_LEFT,COLLISION_SCREENLEFT) && !S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENRIGHTVALUEOUT, DIRECTION_RIGHT, COLLISION_SCREENRIGHT))
	{
		M_Position[0].x += M_Speed * g_gameTime->GetFrameDeltaTime();
		M_Position[1].x -= M_Speed * g_gameTime->GetFrameDeltaTime();
		M_PositionCollision[0].x += M_Speed * g_gameTime->GetFrameDeltaTime();
		M_PositionCollision[1].x -= M_Speed * g_gameTime->GetFrameDeltaTime();
		M_MoveFlag = true;
	}else {
		if (S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENLEFTVALUEOUT,DIRECTION_LEFT,COLLISION_SCREENLEFT) && S_Element.P_Collision->EmptyAndDecisionCollision(COLLISION_SCREENRIGHTVALUEOUT, DIRECTION_RIGHT, COLLISION_SCREENRIGHT))
		{
			M_MoveState = SCREENCHANGE_NON;
			M_AlphaState = SCREENCHANGE_FORWARD;
			M_ChangeState = SCREENCHANGE_LOAD;
			M_Position[0] = M_PositionOut[0];
			M_Position[1] = M_PositionOut[1];
			M_PositionCollision[0] = M_PositionCollisionOut[0];
			M_PositionCollision[1] = M_PositionCollisionOut[1];
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