#pragma once
#include "DimensionalStorage/StructStorage.h"
#include "level2D/Level2DRender.h"
class Opening : public IGameObject
{
public:
	Opening();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_WallTexture;
	SpriteRender M_ButtonTexture;

	Vector3 M_WallPosition;
	Vector3 M_ButtonPosition;

	Level2DRender M_Level2D;

	Vector2 M_Alfha = { 1.0f,0.0f };
	float M_AlfhaSpeed = 3.5f;

	bool M_PowerFlag = false;
	bool M_ClickFlag = true;
	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
	ClassOperation S_Operation;
};

