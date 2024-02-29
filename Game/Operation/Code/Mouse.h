#pragma once
class Data2D;
enum MouseFlagStorage
{
	MOUSE_LEFTCLICK,
	MOUSE_RIGHTCLICK ,
	MOUSE_FLICK
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
	
	Vector3 GetMousePosition()
	{return M_MouseCursorPosition; }
	Vector3 GetMouseMoveSpeed()
	{return M_MouseCursorMoveSpeed;}
	Vector2 GetDelta()
	{return M_Delta;}
private:
	Vector3 M_MouseCursorPosition;
	Vector3 M_MouseCursorMoveSpeed;//マウスカーソルの移動量

	POINT M_CursorPosition = {};
	HWND M_HWnd = GetConsoleWindow();

	Vector2 M_Client      = { 1535.0f , 863.0f };//ウィンドウの縦横
	Vector2 M_Window      = { 1920.0f , 1080.0f };//正規ウィンドウの縦横
	Vector2 M_PrevMouse   = { 0.0f    , 0.0f };//前回のマウス座標
	Vector2 M_Delta       = { 0.0f    , 0.0f };//マウスの相対的な移動量
	Vector2 M_DeltaSpeed  = { 0.0f    , 0.0f };//Deltaをフレーム間で割った数値
	Vector2 M_Converted   = { 0.0f    , 0.0f };//現在のマウス座標

	bool M_LeftClickFlag  = false;
	bool M_RightClickFlag = false;
	bool M_FlickFlag      = false;

	float M_DeltaTime = 0.0f;
	float FlickSpeedThreshold = 6000.0f;

	Data2D* P_Data2D = nullptr;
};