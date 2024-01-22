#pragma once
#include "DimensionalStorage/HeaderStorage.h"
#include "level2D/Level2DRender.h"
class ScreenChange : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void MoveIn();
	void MoveOut();
	void Alpha();
private:
	SpriteRender M_Texture[2];

	Vector3 M_Position[2];
	Vector3 M_PositionIn[2];
	Vector3 M_PositionOut[2];

	Level2DRender M_Level2D;

	int M_MoveState = 0;
	int M_ChangeState = 0;
	float M_Speed = 2000.0f;
	bool M_MoveFlag    = false;
	bool M_MoveInFlag  = true;
	bool M_MoveOutFlag = false;

	Vector2 M_Alpha = { 1.0f,0.0f };
	float M_AlphaSpeed = 1.0f;

	ClassDimensionalElement S_Element;
};

