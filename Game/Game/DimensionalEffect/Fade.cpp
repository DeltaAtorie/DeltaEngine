#include "stdafx.h"
#include "Fade.h"
Fade::Fade()
{
	M_FadeTexture.Init("Assets/Sprite/ClairAction/Fade.DDS",1920.0f,1080.0f,true);
	M_FadeTexture.Update();
}
void Fade::ButtonFade(SpriteRender& Button, bool Press_Button)
{
	if (Press_Button)
	{
		if (M_ButtonFadeInDecision)
		{
			M_ButtonAlpha -= 10.0f * g_gameTime->GetFrameDeltaTime();
			if (M_ButtonAlpha <= 0.0f)
			{
				M_ButtonAlpha = 0.0f;
				M_ButtonFadeInDecision = false;
				M_ButtonFadeOutDecision = true;
			}
		}else {
			if (M_ButtonFadeOutDecision)
			{
				M_ButtonAlpha += 10.0f * g_gameTime->GetFrameDeltaTime();
				if (M_ButtonAlpha >= 1.0f)
				{
					M_ButtonAlpha = 1.0f;
					M_ButtonFadeInDecision = true;
					M_ButtonFadeOutDecision = false;
				}
			}
		}
	}
	else {
		if (M_ButtonFadeInDecision)
		{
			M_ButtonAlpha -= 1.0f * g_gameTime->GetFrameDeltaTime();
			if (M_ButtonAlpha <= 0.0f)
			{
				M_ButtonAlpha = 1.0f;
				M_ButtonFadeInDecision = false;
				M_ButtonFadeOutDecision = true;
			}
		}
		else {
			if (M_ButtonFadeOutDecision)
			{
				M_ButtonAlpha += 1.0f * g_gameTime->GetFrameDeltaTime();
				if (M_ButtonAlpha >= 1.0f)
				{
					M_ButtonAlpha = 1.0f;
					M_ButtonFadeInDecision = true;
					M_ButtonFadeOutDecision = false;
				}
			}
		}
	}
	M_ButtonCollar = { 1.0f,1.0f,1.0f , M_ButtonAlpha };
	Button.SetMulColor(M_ButtonCollar);
}
void Fade::Update()
{
	if (M_State == ENSTATE_FADEIN)
	{
		if (M_AlphaResetDecision)
		{
			M_Alpha = 10.0f;
			M_AlphaResetDecision = false;
		}
		M_Alpha -= FadeSpeed * g_gameTime->GetFrameDeltaTime();
		if (M_Alpha <= 0.0f)
		{
			M_Alpha = 0.0f;
			M_State = ENSTATE_IDLE;
			M_AlphaResetDecision = true;
		}
	}else {
		if (M_State == ENSTATE_FADEOUT)
		{
			if (M_AlphaResetDecision)
			{
				M_Alpha = 0.0f;
				M_AlphaResetDecision = false;
			}
			M_Alpha += FadeSpeed * g_gameTime->GetFrameDeltaTime();
			if (M_Alpha >= 10.0f)
			{
				M_Alpha = 10.0f;
				M_State = ENSTATE_IDLE;
				M_AlphaResetDecision = true;
			}
		}
	}
}
void Fade::Render(RenderContext& rc)
{
	if (M_Alpha > 0.0f)
	{
		M_FadeTexture.SetMulColor({ 1.0f,1.0f,1.0f, M_Alpha });
		M_FadeTexture.Draw(rc);
	}
}