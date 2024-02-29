#pragma once
#include "level2D/Level2DRender.h"
class Data2D;
enum class ScreenDirection
{
	RIGHT,
	LEFT,
	NON,
};
enum class ScreenState
{
	MOVEIN,
	MOVEOUT,
	NON,
};
class ScreenChange2D : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move();
	void MoveIn();
	void MoveOut();

	void ScreenCgangeIn()
	{M_MoveState = ScreenState::MOVEIN;}
	void ScreenCgangeOut()
	{M_MoveState = ScreenState::MOVEOUT;}
private:
	Level2DRender M_Level2D;
	SpriteRender M_Texture[2];
	Vector3 M_Position[2];
	Vector3 M_PositionIn[2];
	Vector3 M_PositionOut[2];

	ScreenState M_MoveState = ScreenState::NON;
	float M_Speed   = 2000.0f;

	Data2D* P_Data2D = nullptr;
};

