#pragma once
#include "DimensionalStorage/StructStorage.h"
#include "level2D/Level2DRender.h"
class Opening : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void PowerButton();
	void CurrentTime();
private:
	SpriteRender M_WallTexture;
	SpriteRender M_PowerButtonTexture;
	SpriteRender M_MusicButtonTexture;
	SpriteRender M_UiFrameTexture;
	Level2DRender M_Level2D;

	Vector2 M_Alfha = { 1.0f,0.0f };
	float M_AlfhaSpeed = 3.5f;

	bool M_PowerFlag = false;
	bool M_ClickFlag = true;

	SYSTEMTIME M_CurrentTime;
	SpriteRender M_HourTexture[3];
	SpriteRender M_MinuteTexture[3];
	SpriteRender M_ColonTexture;
	int M_Hour[3];
	int M_Minute[3];

	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
	ClassOperation S_Operation;
};

