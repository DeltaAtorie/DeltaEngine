#pragma once
#include "DimensionalStorage/HeaderStorage.h"
#include "level2D/Level2DRender.h"
class Load : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	Level2DRender M_Level2D;
	SpriteRender M_LoadTexture;
	SpriteRender M_LoadCountTexture[3];
	Vector2 M_LoadPercent = { 1.0f,0.0f };

	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
};

