#pragma once
#include "level2D/Level2DRender.h"
class Data2D;
class Ui : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	Level2DRender M_Level2D;
	SpriteRender M_UiFrameTexture;
	SpriteRender M_UiPercentTexture;
	SpriteRender M_UiLifeTexture;
	SpriteRender M_UiGunTexture[3];
	SpriteRender M_UiIconTexture[2];

	Data2D* P_Data2D = nullptr;
};

