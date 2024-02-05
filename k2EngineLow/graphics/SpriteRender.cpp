#include "k2EngineLowPreCompile.h"
#include "SpriteRender.h"

namespace nsK2EngineLow
{
	void SpriteRender::Init
	(
		const char* Sprite,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/ColorOut.fx";
		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";
		
		InitData.m_ddsFilePath[0] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		InitData.m_alphaBlendMode = alphaBlendMode;

		M_WideAndHeight.x = w;
		M_WideAndHeight.y = h;

		m_sprite.Init(InitData);
	}

	void SpriteRender::WeatherInit
	(
		const char* Sprite,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/Weather.fx";
		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		InitData.m_ddsFilePath[0] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		InitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(InitData);
	}

	void SpriteRender::CurrentTimeInit
	(
		const char* Sprite,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/Time.fx";

		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		InitData.m_ddsFilePath[0] = "Assets/Sprite/Count/0.DDS";
		InitData.m_ddsFilePath[1] = "Assets/Sprite/Count/1.DDS";
		InitData.m_ddsFilePath[2] = "Assets/Sprite/Count/2.DDS";
		InitData.m_ddsFilePath[3] = "Assets/Sprite/Count/3.DDS";
		InitData.m_ddsFilePath[4] = "Assets/Sprite/Count/4.DDS";
		InitData.m_ddsFilePath[5] = "Assets/Sprite/Count/5.DDS";
		InitData.m_ddsFilePath[6] = "Assets/Sprite/Count/6.DDS";
		InitData.m_ddsFilePath[7] = "Assets/Sprite/Count/7.DDS";
		InitData.m_ddsFilePath[8] = "Assets/Sprite/Count/8.DDS";
		InitData.m_ddsFilePath[9] = "Assets/Sprite/Count/9.DDS";
		InitData.m_ddsFilePath[10] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		InitData.m_expandConstantBuffer = &S_CurrentTime;
		InitData.m_expandConstantBufferSize = sizeof(S_CurrentTime);

		InitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(InitData);
	}

	void SpriteRender::SymbolInit
	(
		const char* Sprite,
		int State,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/Symbol.fx";

		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		InitData.m_ddsFilePath[0] = "Assets/Sprite/Symbol/Colon.DDS";
		InitData.m_ddsFilePath[1] = "Assets/Sprite/Symbol/PerCent.DDS";
		InitData.m_ddsFilePath[2] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		S_Symbol.State = State;
		InitData.m_expandConstantBuffer = &S_Symbol;
		InitData.m_expandConstantBufferSize = sizeof(S_Symbol);

		InitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(InitData);
	}

	void SpriteRender::AnimationInit
	(
		const char* Sprite[],
		int FrameLimit,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/Animation.fx";
		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		for (int i = 0 ; i < FrameLimit ; i++)
		{InitData.m_ddsFilePath[i] = Sprite[i];}

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		S_Animation.AnimationFrameLimit = FrameLimit;
		InitData.m_expandConstantBuffer = &S_Animation;
		InitData.m_expandConstantBufferSize = sizeof(S_Animation);

		InitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(InitData);
	}

	void SpriteRender::PercentInit
	(
		const char* Sprite1,
		const char* Sprite2,
		int State,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/Percent.fx";
		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		InitData.m_ddsFilePath[0] = Sprite1;
		InitData.m_ddsFilePath[1] = Sprite2;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		S_Percent.State = State;
		InitData.m_expandConstantBuffer = &S_Percent;
		InitData.m_expandConstantBufferSize = sizeof(S_Percent);

		InitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(InitData);
	}

	void SpriteRender::TestInit
	(
		const char* Sprite,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/Test.fx";
		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		InitData.m_ddsFilePath[0] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		InitData.m_expandConstantBuffer = &S_Test;
		InitData.m_expandConstantBufferSize = sizeof(S_Test);

		InitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(InitData);
	}

	void SpriteRender::Draw(RenderContext& rc)
	{
		g_renderingEngine->InRenderObject(this);
	}
	
	void SpriteRender::OnRender2D(RenderContext& rc)
	{
		m_sprite.Draw(rc);
	}
}

