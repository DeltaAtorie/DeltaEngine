#include "stdafx.h"
#include "ScreenChange2D.h"
#include "Storage2D/Header2D.h"
bool ScreenChange2D::Start()
{
	P_Data2D = FindGO<Data2D>("data2d");
	P_Data2D->Data2DFindGO();

	int M_Direction = static_cast<int>(ScreenDirection::NON);

	M_Level2D.Init("Assets/Sprite/ScreenChange2D/ScreenChange2D.casl" , [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("RightIn") == true)
		{
			M_Direction = static_cast<int>(ScreenDirection::RIGHT);
			M_PositionIn[M_Direction] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("RightOut") == true)
		{
			M_Direction = static_cast<int>(ScreenDirection::RIGHT);
			M_PositionOut[M_Direction] = objData.position;
			return true;
		}

		if (objData.EqualObjectName("LeftIn") == true)
		{
			M_Direction = static_cast<int>(ScreenDirection::LEFT);
			M_PositionIn[M_Direction] = objData.position;
			return true;
		}
		if (objData.EqualObjectName("LeftOut") == true)
		{
			M_Direction = static_cast<int>(ScreenDirection::LEFT);
			M_PositionOut[M_Direction] = objData.position;
			return true;
		}
	});
	M_Level2D.Init("Assets/Sprite/ScreenChange2D/ScreenChange2D.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("Right") == true)
		{
			M_Direction = static_cast<int>(ScreenDirection::RIGHT);

			M_Texture[M_Direction].PercentInit("Assets/Sprite/ScreenChange2D/ScreenChangeRight.DDS" , "Assets/Sprite/ScreenChange2D/ScreenChangeRightLoad.DDS" , 5 , 960.0f , 1080.0f);
			if (M_MoveState == ScreenState::MOVEIN || M_MoveState == ScreenState::NON)
			{
				M_Position[M_Direction] = M_PositionOut[M_Direction];
			}else {
				if (M_MoveState == ScreenState::MOVEOUT)
				{
					M_Position[M_Direction] = M_PositionIn[M_Direction];
				}
			}
			M_Texture[M_Direction].SetPosition(M_Position[M_Direction]);
			M_Texture[M_Direction].Update();

			P_Data2D->P_Collision2D->BodyDataSet(960.0f , 1080.0f , M_Position[M_Direction].x    , M_Position[M_Direction].y    , "ScreenRight"      , "Non");
			P_Data2D->P_Collision2D->BodyDataSet(960.0f , 1080.0f , M_PositionOut[M_Direction].x , M_PositionOut[M_Direction].y , "ScreenRightValue" , "Non");
			return true;
		}

		if (objData.EqualObjectName("Left") == true)
		{
			M_Direction = static_cast<int>(ScreenDirection::LEFT);

			M_Texture[M_Direction].PercentInit("Assets/Sprite/ScreenChange2D/ScreenChangeLeft.DDS" , "Assets/Sprite/ScreenChange2D/ScreenChangeLeftLoad.DDS" , 5 , 960.0f , 1080.0f);
			if (M_MoveState == ScreenState::MOVEIN || M_MoveState == ScreenState::NON)
			{
				M_Position[M_Direction] = M_PositionOut[M_Direction];
			}else {
				if (M_MoveState == ScreenState::MOVEOUT)
				{
					M_Position[M_Direction] = M_PositionIn[M_Direction];
				}
			}
			M_Texture[M_Direction].SetPosition(M_Position[M_Direction]);
			M_Texture[M_Direction].Update();
			P_Data2D->P_Collision2D->BodyDataSet(960.0f , 1080.0f , M_Position[M_Direction].x    , M_Position[M_Direction].y    , "ScreenLeft"      , "Non");
			P_Data2D->P_Collision2D->BodyDataSet(960.0f , 1080.0f , M_PositionOut[M_Direction].x , M_PositionOut[M_Direction].y , "ScreenLeftValue" , "Non");
			return true;
		}
	});
	return true;
}
void ScreenChange2D::Update()
{
	Move();

	SpriteRender* Sprite[2] = { &M_Texture[static_cast<int>(ScreenDirection::RIGHT)]  , &M_Texture[static_cast<int>(ScreenDirection::LEFT)]};
	Vector3* Position[2]    = { &M_Position[static_cast<int>(ScreenDirection::RIGHT)] , &M_Position[static_cast<int>(ScreenDirection::LEFT)]};
	const char* Path[2]     = { "ScreenRight" , "ScreenLeft" };

	//座標更新
	for (int i = 0 ; i < sizeof(Sprite) / sizeof(Sprite[0]) ; i++)
	{P_Data2D->P_Helper2D->SpriteUpdate(Sprite[i], Position[i]);}

	//パーセント更新
	for (int i = 0 ; i < sizeof(Sprite) / sizeof(Sprite[0]) ; i++)
	{Sprite[i]->PercentSet(P_Data2D->P_Load2D->GetLoadPercent());}

	//判定更新
	for (int i = 0 ; i < sizeof(Sprite) / sizeof(Sprite[0]) ; i++)
	{P_Data2D->P_Collision2D->BodySetPosition(M_Position[i].x, M_Position[i].y, Path[i]);}
}
void ScreenChange2D::Render(RenderContext& rc)
{
	P_Data2D->P_Helper2D->SpriteDraw(M_Texture, rc, sizeof(M_Texture) / sizeof(M_Texture[0]));
}

void ScreenChange2D::Move()
{
	switch (M_MoveState)
	{
	case ScreenState::MOVEIN:
		MoveIn();
		break;
	case ScreenState::MOVEOUT:
		MoveOut();
		break;
	}
}
void ScreenChange2D::MoveIn()
{
	if (!P_Data2D->P_Collision2D->BodyAndBodyCollision("ScreenRight" , "ScreenLeft"))
	{
		P_Data2D->P_Helper2D->Increase(M_Position[static_cast<int>(ScreenDirection::LEFT)].x  , M_Speed);
		P_Data2D->P_Helper2D->Decrease(M_Position[static_cast<int>(ScreenDirection::RIGHT)].x , M_Speed);

		P_Data2D->P_Helper2D->OverflowUp(M_Position[static_cast<int>(ScreenDirection::LEFT)].x    , M_PositionIn[static_cast<int>(ScreenDirection::LEFT)].x);
		P_Data2D->P_Helper2D->OverflowDown(M_Position[static_cast<int>(ScreenDirection::RIGHT)].x , M_PositionIn[static_cast<int>(ScreenDirection::RIGHT)].x);
	}else {
		if (P_Data2D->P_Collision2D->BodyAndBodyCollision("ScreenRight" , "ScreenLeft"))
		{
			M_MoveState = ScreenState::NON;
			P_Data2D->P_Load2D->SetFileLoad(LoadFile::GAME);
		}
	}
}
void ScreenChange2D::MoveOut()
{
	if (!P_Data2D->P_Collision2D->EmptyAndBodyCollision("ScreenLeftValue", DIRECTION_LEFT, "ScreenLeft") && !P_Data2D->P_Collision2D->EmptyAndBodyCollision("ScreenRightValue", DIRECTION_RIGHT, "ScreenRight"))
	{
		P_Data2D->P_Helper2D->Increase(M_Position[static_cast<int>(ScreenDirection::RIGHT)].x , M_Speed);
		P_Data2D->P_Helper2D->Decrease(M_Position[static_cast<int>(ScreenDirection::LEFT)].x  , M_Speed);

		P_Data2D->P_Helper2D->OverflowUp(M_Position[static_cast<int>(ScreenDirection::RIGHT)].x  , M_PositionOut[static_cast<int>(ScreenDirection::RIGHT)].x);
		P_Data2D->P_Helper2D->OverflowDown(M_Position[static_cast<int>(ScreenDirection::LEFT)].x , M_PositionOut[static_cast<int>(ScreenDirection::LEFT)].x);
	}else {
		if (P_Data2D->P_Collision2D->EmptyAndBodyCollision("ScreenLeftValue" , DIRECTION_LEFT , "ScreenLeft") && P_Data2D->P_Collision2D->EmptyAndBodyCollision("ScreenRightValue" , DIRECTION_RIGHT , "ScreenRight"))
		{
			M_MoveState = ScreenState::NON;
			P_Data2D->P_Load2D->ResetFileLoad();
		}
	}
}