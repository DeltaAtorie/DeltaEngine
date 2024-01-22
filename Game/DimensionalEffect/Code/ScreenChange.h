#pragma once
#include "DimensionalStorage/StructStorage.h"
#include "level2D/Level2DRender.h"
class ScreenChange : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void MoveIn();
	void MoveOut();
private:
	SpriteRender M_Texture[2];

	Vector3 M_Position[2];
	Vector3 M_PositionIn[2];
	Vector3 M_PositionOut[2];

	Level2DRender M_Level2D;

	float M_Speed = 2000.0f;
	bool M_MoveFlag    = false;
	bool M_MoveInFlag  = false;
	bool M_MoveOutFlag = true;

	ClassDimensionalElement S_Element;
};

