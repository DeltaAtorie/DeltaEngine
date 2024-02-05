#pragma once
#include "DimensionalStorage/HeaderStorage.h"
#include "level2D/Level2DRender.h"
enum ScreenChangeStorage
{
	SCREENCHANGE_RIGHT,
	SCREENCHANGE_LEFT,

	SCREENCHANGE_IN,
	SCREENCHANGE_OUT,

	SCREENCHANGE_NON,
};
class ScreenChange : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move();
	void MoveIn();
	void MoveOut();

	void ScreenCgangeIn()
	{M_MoveState = SCREENCHANGE_IN;}
	void ScreenCgangeOut()
	{M_MoveState = SCREENCHANGE_OUT;}
private:
	SpriteRender M_Texture[2];

	Vector3 M_Position[2];
	Vector3 M_PositionIn[2];
	Vector3 M_PositionOut[2];
	Level2DRender M_Level2D;

	int M_MoveState   = SCREENCHANGE_IN;
	float M_Speed     = 2000.0f;

	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
};

