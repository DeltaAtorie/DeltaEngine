#include "stdafx.h"
#include "Opening.h"
#include "DimensionalStorage/HeaderStorage.h"
bool Opening::Start()
{
	S_Operation.P_Mouse = FindGO<Mouse>("mouse");
	S_Effect.P_Sound = FindGO<Sound>("sound");
	S_Effect.P_Fade = FindGO<Fade>("fade");
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");

	M_Level2D.Init("Assets/Sprite/Opening/Opening.casl", [&](Level2DRenderObjectData& objData)
	{
		if (objData.EqualObjectName("WallPaper") == true)
		{
			M_WallTexture.FadeInit("Assets/Sprite/Opening/WallPaperOff.DDS", "Assets/Sprite/Opening/WallPaperOn.DDS", &M_Alpha, 1920.0f, 1080.0f);
			M_WallTexture.SetPosition(objData.position);
			M_WallTexture.Update();
			return true;
		}
		if (objData.EqualObjectName("PowerButton") == true)
		{
			M_PowerButtonTexture.FadeInit("Assets/Sprite/Opening/PowerButton.DDS", "Assets/Sprite/Opening/WallPaper.DDS", &M_Alpha, 100.0f, 100.0f);
			S_Element.P_Collision->DecisionDataSet(100, 100, objData.position.x, objData.position.y, COLLISION_POWERBUTTON, TAG_NON);
			M_PowerButtonTexture.SetPosition(objData.position);
			M_PowerButtonTexture.Update();
			return true;
		}
		if (objData.EqualObjectName("MusicButton") == true)
		{
			M_SoundButtonTexture.FadeInit("Assets/Sprite/Opening/SoundButton.DDS", "Assets/Sprite/Opening/WallPaper.DDS", &M_Alpha, 100.0f, 100.0f);
			M_SoundButtonTexture.SetPosition(objData.position);
			M_SoundButtonTexture.Update();

			M_MuteButtonTexture.FadeInit("Assets/Sprite/Opening/MuteButton.DDS", "Assets/Sprite/Opening/WallPaper.DDS", &M_Alpha, 100.0f, 100.0f);
			M_MuteButtonTexture.SetPosition(objData.position);
			M_MuteButtonTexture.Update();
			
			S_Element.P_Collision->DecisionDataSet(100, 100, objData.position.x, objData.position.y, COLLISION_MUSICBUTTON, TAG_NON);
			return true;
		}
		if (objData.EqualObjectName("Frame") == true)
		{
			M_UiFrameTexture.FadeInit("Assets/Sprite/Opening/FrameOff.DDS", "Assets/Sprite/Opening/FrameOn.DDS", &M_Alpha, 1920.0f, 1080.0f);
			M_UiFrameTexture.SetPosition(objData.position);
			M_UiFrameTexture.Update();
			return true;
		}
		if (objData.EqualObjectName("Colon") == true)
		{
			return true;
		}
		if (objData.EqualObjectName("Hour10") == true)
		{
			M_HourTexture[1].CurrentTimeInit("Assets/Sprite/Opening/WallPaper.DDS", 80.0f, 80.0f);
			M_HourTexture[1].SetPosition(objData.position);
			M_HourTexture[1].Update();
			return true;
		}
		if (objData.EqualObjectName("Hour1") == true)
		{
			M_HourTexture[2].CurrentTimeInit("Assets/Sprite/Opening/WallPaper.DDS",80.0f, 80.0f);
			M_HourTexture[2].SetPosition(objData.position);
			M_HourTexture[2].Update();
			return true;
		}
		if (objData.EqualObjectName("Minute10") == true)
		{
			M_MinuteTexture[1].CurrentTimeInit("Assets/Sprite/Opening/WallPaper.DDS",80.0f, 80.0f);
			M_MinuteTexture[1].SetPosition(objData.position);
			M_MinuteTexture[1].Update();
			return true;
		}
		if (objData.EqualObjectName("Minute1") == true)
		{
			M_MinuteTexture[2].CurrentTimeInit("Assets/Sprite/Opening/WallPaper.DDS",80.0f, 80.0f);
			M_MinuteTexture[2].SetPosition(objData.position);
			M_MinuteTexture[2].Update();
			return true;
		}
	});
	return true;
}
void Opening::Update()
{
	Cool();
	Alpha();
	PowerButton();
	SoundButton();
	CurrentTime();
}
void Opening::Render(RenderContext& rc)
{
	M_WallTexture.Draw(rc);
	//M_UiFrameTexture.Draw(rc);
	
	M_PowerButtonTexture.Draw(rc);
	/*if (!M_MuteFlag)
	{
		M_SoundButtonTexture.Draw(rc);
	}else {
		if (M_MuteFlag)
		{
			M_MuteButtonTexture.Draw(rc);
		}
	}*/

	//M_ColonTexture.Draw(rc);
	//M_HourTexture[1].Draw(rc);
	//M_HourTexture[2].Draw(rc);
	//M_MinuteTexture[1].Draw(rc);
	//M_MinuteTexture[2].Draw(rc);
}

void Opening::Cool()
{
	if (!M_ClickFlag)
	{
		M_CoolTime+= M_CoolSpeed * g_gameTime->GetFrameDeltaTime();
		if (M_CoolTime > 1.0f)
		{
			M_CoolTime = 0.0f;
			M_ClickFlag = true;
		}
	}
}
void Opening::Alpha()
{
	if (!M_ClickFlag)
	{
		if (!M_PowerFlag)
		{
			if (M_Alpha.x < 1.0f && M_Alpha.y > 0.0f)
			{
				M_Alpha.x += M_AlphaSpeed * g_gameTime->GetFrameDeltaTime();
				M_Alpha.y -= M_AlphaSpeed * g_gameTime->GetFrameDeltaTime();
			}
		}else {
			if (M_PowerFlag)
			{
				if (M_Alpha.x > 0.0f && M_Alpha.y < 1.0f)
				{
					M_Alpha.x -= M_AlphaSpeed * g_gameTime->GetFrameDeltaTime();
					M_Alpha.y += M_AlphaSpeed * g_gameTime->GetFrameDeltaTime();
				}
			}
		}
	}
}
void Opening::PowerButton()
{
	if (M_ClickFlag)
	{
		if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_MOUSE, COLLISION_POWERBUTTON))
		{
			if (S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON) && !M_PowerFlag)
			{
				M_PowerFlag = true;
				M_ClickFlag = false;
			}else {
				if (S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON) && M_PowerFlag)
				{
					M_PowerFlag = false;
					M_ClickFlag = false;
				}
			}
		}
	}
}
void Opening::SoundButton()
{
	if (M_ClickFlag)
	{
		if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_MOUSE, COLLISION_MUSICBUTTON))
		{
			if (S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON) && !M_MuteFlag)
			{
				M_MuteFlag = true;
				M_ClickFlag = false;
			}else {
				if (S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON) && M_MuteFlag)
				{
					M_MuteFlag = false;
					M_ClickFlag = false;
				}
			}
		}
	}
}
void Opening::CurrentTime()
{
	GetLocalTime(&M_CurrentTime);

	if (M_CurrentTime.wHour != M_Hour[0] || M_CurrentTime.wMinute != M_Minute[0])
	{
		M_Hour[0] = M_CurrentTime.wHour;
		M_Minute[0] = M_CurrentTime.wMinute;

		M_Hour[1] = M_Hour[0] / 10;
		M_Hour[2] = M_Hour[0] % 10;

		M_Minute[1] = M_Minute[0] / 10;
		M_Minute[2] = M_Minute[0] % 10;
	}
	M_HourTexture[1].CurrentTimeSet(M_Hour[1]);
	M_HourTexture[2].CurrentTimeSet(M_Hour[2]);
	M_MinuteTexture[1].CurrentTimeSet(M_Minute[1]);
	M_MinuteTexture[2].CurrentTimeSet(M_Minute[2]);
}