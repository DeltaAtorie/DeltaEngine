#pragma once
#include "Storage2D/Utility2D.h"
#include "level2D/Level2DRender.h"
class Sprite2D;
class Data2D;
class Operation;
class Opening2D : public IGameObject
{
public:
	Opening2D() : 
	S_Percent(1.0f, 0.0f, 1.5f),
	S_CoolFlag(0.5f, 1.5f) {};
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void PowerUpdate();
	void CollisionUpdate();
private:
	SpriteRender M_GameTitleTexture;
	SpriteRender M_StartButtonTexture;
	SpriteRender M_OptionButtonTexture;
	SpriteRender M_PowerButtonTexture;
	Level2DRender M_Level2D;

	Percent S_Percent;
	CoolFlag S_CoolFlag;

	bool M_PowerFlag = true;

	Sprite2D* P_Sprite2D = nullptr;
	Data2D* P_Data2D = nullptr;
	Operation* P_Operation = nullptr;
};

