#pragma once
#include "DimensionalStorage/StructStorage.h"
struct MouseFlag
{
	bool M_LeftButtonFlag = false;
	bool M_RightButtonFlag = false;
	bool M_FlickFlag = false;
	bool M_WheelFlag = false;
};
class Mouse : public IGameObject
{
public:
	bool Start();
	void Update();
	
	void MouseCurSorSetPosition(Vector3& Position);

	void MouseMove();
	void MouseSet();

	void MouseFlagJudge();
	bool GetMouseFlag(int Number);
	void SetMouseFlag(int Number,bool Flag);
	
	Vector3 GetMousePosition()
	{return M_MouseCousorPosition; }

	Vector3 GetMouseMoveSpeed()
	{return M_MouseCousorMoveSpeed;}

	Vector2 GetDelta()
	{return M_Delta;}
private:
	Vector3 M_MouseCousorPosition;
	Vector3 M_MouseCousorMoveSpeed;

	POINT M_CursorPosition = {};
	HWND M_HWnd = GetConsoleWindow();

	Vector2 M_Client      = { 1535.0f , 863.0f };//ウィンドウの縦横
	Vector2 M_Window      = { 1920.0f , 1080.0f };//正規ウィンドウの縦横
	Vector2 M_PrevMouse   = { 0.0f    , 0.0f };
	Vector2 M_Delta       = { 0.0f    , 0.0f };//マウスの移動量
	Vector2 M_DeltaSpeed  = { 0.0f    , 0.0f };//
	Vector2 M_Converted   = { 0.0f    , 0.0f };

	MouseFlag S_Flag;

	float M_DeltaTime = 0.0f;
	float FlickSpeedThreshold = 6000.0f;

	ClassDimensionalElement S_Element;
};