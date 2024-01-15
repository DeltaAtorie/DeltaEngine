#include "stdafx.h"
#include "DimensionalAnimation.h"
DimensionalAnimation::DimensionalAnimation()
{
	M_TextureFilePath = "Assets/Sprite/Animation/Animation1.DDS";
	M_AnimationTexture.Init(M_TextureFilePath, 1920.0f, 1080.0f, true);
}
void DimensionalAnimation::Update()
{
	if (M_Animation != ANIMATION_NON)
	{
		M_Frame++;
		if (M_Frame > M_FrameLimit)
		{
			M_Frame = 0;
			M_AnimationFrame++;

			if (M_AnimationFrame > M_AnimationFrameLimit)
			{M_AnimationFrame = 1;}

			GetFilePath();
			M_AnimationTexture.TextureSet(M_TextureFilePath);
		}
		M_AnimationTexture.Update();
	}
}
void DimensionalAnimation::Render(RenderContext& rc)
{
	if (M_Animation != ANIMATION_NON)
	{M_AnimationTexture.Draw(rc);}
}

void DimensionalAnimation::SetAnimationFrame(int Animation)
{
	switch (Animation)
	{
	case ANIMATION_OPENING:
		M_Animation = ANIMATION_OPENING;
		M_AnimationFrameLimit = 3;
		break;

	}
}

void DimensionalAnimation::GetFilePath()
{
	switch (M_Animation)
	{
	case ANIMATION_OPENING:
		GetOpening();
		break;

	}
}
void DimensionalAnimation::GetOpening()
{
	switch (M_AnimationFrame)
	{
	case 1:
		M_TextureFileMemoryPath = "Assets/Sprite/Animation/Animation1.DDS";
		break;
	case 2:
		M_TextureFileMemoryPath = "Assets/Sprite/Animation/Animation2.DDS";
		break;
	case 3:
		M_TextureFileMemoryPath = "Assets/Sprite/Animation/Animation3.DDS";
		break;
	}
	M_TextureFilePath = M_TextureFileMemoryPath;
}