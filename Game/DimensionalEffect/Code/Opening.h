#pragma once
#include "DimensionalStorage/StructStorage.h"
#include "level2D/Level2DRender.h"
class Opening : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Cool();
	void Alpha();
	void PowerButton();
	void SoundButton();
	void CurrentTime();
private:
	SpriteRender M_WallTexture;
	SpriteRender M_PowerButtonTexture;
	SpriteRender M_SoundButtonTexture;
	SpriteRender M_MuteButtonTexture;
	SpriteRender M_UiFrameTexture;
	Level2DRender M_Level2D;

	Vector2 M_Alpha = { 1.0f,0.0f };
	float M_AlphaSpeed = 3.5f;

	float M_CoolTime  = 0.0f;
	float M_CoolSpeed = 3.0f;

	bool M_PowerFlag = true;//�d��
	bool M_MuteFlag  = false;//���ʐݒ�
	bool M_ClickFlag = true;//�{�^���̑ҋ@����

	SYSTEMTIME M_CurrentTime;
	SpriteRender M_HourTexture[3];
	SpriteRender M_MinuteTexture[3];
	int M_Hour[3];
	int M_Minute[3];

	//const char* browserPath = "C:\\Program Files\\Internet Explorer\\iexplore.exe";
	//const char* urlToOpen   = "https://twitter.com/xionioyuni37226";
	//HINSTANCE result = ShellExecuteA(NULL, "open", browserPath, urlToOpen, NULL, SW_SHOWNORMAL);

	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
	ClassOperation S_Operation;
};

