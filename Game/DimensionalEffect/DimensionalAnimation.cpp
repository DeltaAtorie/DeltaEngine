#include "stdafx.h"
#include "DimensionalAnimation.h"
DimensionalAnimation::DimensionalAnimation()
{
	M_TextureFileValuePath = "Assets/Sprite/Animation/";
}
void DimensionalAnimation::Update()
{
	M_Frame++;
	if (M_Frame > M_FrameLimit)
	{
		M_Frame = 0;
		M_AnimationTexture.TextureSet(M_TextureFilePath);
		M_TextureFilePath = M_TextureFileValuePath;
	}

	M_AnimationTexture.Update();
}
void DimensionalAnimation::Render(RenderContext& rc)
{
	M_AnimationTexture.Draw(rc);
}