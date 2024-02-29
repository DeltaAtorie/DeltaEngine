#pragma once
enum
{
	OPTION_MEMORY,
	OPTION_PLUS,
	OPTION_MINUS,
	OPTION_NAME
};
#include "Storage2D/Utility2D.h"
#include "level2D/Level2DRender.h"
class Data2D;
class Operation;
class OptionSprite2D : public IGameObject
{
public:
	OptionSprite2D() :
	S_BgmPercent(1.0f, 0.0f, 1.5f),
	S_SePercent(1.0f, 0.0f, 1.5f),
	S_UiPercent(1.0f, 0.0f, 1.5f),
	S_AlphaPercent(1.0f, 0.0f, 3.0f),
	S_CoolFlag(0.1f, 1.5f) {};
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Button();
	void PlusButton();
	void MinusButton();
	float GetBgm()
	{return S_BgmPercent.GetPercent();}
	float GetSe()
	{return S_SePercent.GetPercent();}
	float GetUi()
	{return S_UiPercent.GetPercent();}

	void Power();
	void PowerSwitch();
	bool GetPower()
	{return M_PowerFlag;}
private:
	Level2DRender M_Level2D;
	SpriteRender M_OptionFrameTexture;
	SpriteRender M_BgmTexture[4];
	SpriteRender M_SeTexture[4];
	SpriteRender M_AlphaTexture[4];

	Percent S_BgmPercent;
	Percent S_SePercent;
	Percent S_UiPercent;
	Percent S_AlphaPercent;
	CoolFlag S_CoolFlag;

	bool M_PowerFlag = false;

	Data2D* P_Data2D       = nullptr;
	Operation* P_Operation = nullptr;
};

