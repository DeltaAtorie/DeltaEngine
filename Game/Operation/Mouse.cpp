#include "stdafx.h"
#include "Mouse.h"
#include "DimensionalStorage/NumberStorage.h"
void Mouse::Update()
{
	M_HWnd = GetConsoleWindow();
    GetCursorPos(&M_CursorPosition);
    ScreenToClient(M_HWnd, &M_CursorPosition);
    MouseSet();
	MouseMove();
    MouseCorsorTextureSetCheck();
	MouseFlagJudge();
    MouseCurSorSetPosition(M_MouseCousorPosition);
    M_MouseCursorTexture.SetPosition(M_MouseCousorPosition);
    M_MouseCursorTexture.Update();
}
void Mouse::Render(RenderContext& rc)
{
	if (M_MouseCursorTexture.GetInitFlag())
	{M_MouseCursorTexture.Draw(rc);}
}

void Mouse::MouseCurSorSetPosition(Vector3& Position)
{
	Position.x = (M_Converted.x - (M_Window.x / 2));
	Position.y = (M_Converted.y - (M_Window.y / 2)) * -1;
}

void Mouse::MouseMove()
{
	M_MouseCousorMoveSpeed.x = 0.0f;
	M_MouseCousorMoveSpeed.y = 0.0f;

	M_Delta.x = M_Converted.x - M_PrevMouse.x;
	M_Delta.y = M_Converted.y - M_PrevMouse.y;

	M_DeltaTime = g_gameTime->GetFrameDeltaTime();

	M_DeltaSpeed.x = M_Delta.x / M_DeltaTime;
	M_DeltaSpeed.y = M_Delta.y / M_DeltaTime;

	if (S_Flag.M_LeftButtonFlag)
	{
		M_MouseCousorMoveSpeed.x = M_Delta.x;
		M_MouseCousorMoveSpeed.y = M_Delta.y * -1.0f;
	}
	
	M_PrevMouse.x = M_Converted.x;
	M_PrevMouse.y = M_Converted.y;
}
void Mouse::MouseSet()
{
	M_Converted.x = (M_CursorPosition.x * M_Window.x) / M_Client.x;
	M_Converted.y = (M_CursorPosition.y * M_Window.y) / M_Client.y;
}
void Mouse::MouseReset()
{
	SetCursorPos(M_Client.x / 2, M_Client.y / 2);
}

void Mouse::MouseCursorTextureSet(const char* Sprite, const float w, const float h, bool ColorOut)
{
    M_MouseCursorTexture.Init(Sprite, w, h, ColorOut);
}
void Mouse::MouseCorsorTextureSetCheck()
{
	if (M_MouseCursorTexture.GetInitFlag())
	{
		ShowCursor(false);
	}else {
		if (!M_MouseCursorTexture.GetInitFlag())
		{
			ShowCursor(true);
		}
	}
}

void Mouse::MouseFlagJudge()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{S_Flag.M_LeftButtonFlag = true;}
	else
	{S_Flag.M_LeftButtonFlag = false;}

	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{S_Flag.M_RightButtonFlag = true;}
	else
	{S_Flag.M_RightButtonFlag = false;}

	if (abs(M_DeltaSpeed.x) > FlickSpeedThreshold || abs(M_DeltaSpeed.y) > FlickSpeedThreshold)
	{S_Flag.M_FlickFlag = true;}
	else 
	{S_Flag.M_FlickFlag = false;}

}
void Mouse::SetMouseFlag(int Number,bool Flag)
{
	switch (Number)
	{
	case MOUSE_LEFTBUTTON:
		S_Flag.M_LeftButtonFlag = Flag;
		break;
	case MOUSE_RIGHTBUTTON:
		S_Flag.M_RightButtonFlag = Flag;
		break;
	case MOUSE_FLICK:
		S_Flag.M_FlickFlag = Flag;
		break;
	}
}
bool Mouse::GetMouseFlag(int Number)
{
	switch (Number)
	{
	case MOUSE_LEFTBUTTON:
		return S_Flag.M_LeftButtonFlag;
		break;
	case MOUSE_RIGHTBUTTON:
		return S_Flag.M_RightButtonFlag;
		break;
	case MOUSE_FLICK:
		return S_Flag.M_FlickFlag;
		break;
	}
}