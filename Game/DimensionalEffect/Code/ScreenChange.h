#pragma once
#include "DimensionalStorage/HeaderStorage.h"
#include "level2D/Level2DRender.h"
enum ScreenChangeStorage
{
	SCREENCHANGE_IN,
	SCREENCHANGE_OUT,

	SCREENCHANGE_LOAD,

	SCREENCHANGE_FORWARD,
	SCREENCHANGE_REVERSE,
	
	SCREENCHANGE_NON,
};
class ScreenChange : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void MoveIn();
	void MoveOut();
	void AlphaUpdate();

	void ScreenCgangeIn()
	{M_MoveState = SCREENCHANGE_IN;}
	void ScreenCgangeOut()
	{M_MoveState = SCREENCHANGE_OUT;}
private:
	SpriteRender M_Texture[2];

	Vector3 M_Position[2];
	Vector3 M_PositionIn[2];
	Vector3 M_PositionOut[2];
	Vector3 M_PositionCollision[2];
	Vector3 M_PositionCollisionIn[2];
	Vector3 M_PositionCollisionOut[2];

	Level2DRender M_Level2D;

	int M_MoveState   = SCREENCHANGE_IN;
	int M_ChangeState = SCREENCHANGE_NON;
	int M_AlphaState  = SCREENCHANGE_NON;
	float M_Speed     = 2000.0f;
	bool M_MoveFlag   = false;

	bool Flag = false;

	Vector2 M_Alpha = { 1.0f,0.0f };
	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
};

