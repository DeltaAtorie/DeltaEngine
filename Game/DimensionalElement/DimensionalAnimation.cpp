#include "stdafx.h"
#include "DimensionalAnimation.h"
DimensionalAnimation::DimensionalAnimation()
{

}
void DimensionalAnimation::Update()
{
	M_AnimationFrame++;
	if (M_AnimationFrame > 60)
	{
		M_AnimationCount++;
		if (M_Animations[M_AnimationCount] == nullptr)
		{
			M_AnimationCount = 0;
			M_AnimationFrame = 0;
		}
		//M_Animation.TextureSet(M_Animations[M_AnimationCount]);
	}
	M_Animation.SetPosition(M_AnimationPosition);
	M_Animation.Update();
}
void DimensionalAnimation::Render(RenderContext& rc)
{
	M_Animation.Draw(rc);
}

void DimensionalAnimation::TextureSet(char* Sprite)
{
	for (int Count = 0 ; 1 ; Count++)
	{
		if (M_Animations[Count] == nullptr)
		{
			M_Animations[Count] = Sprite;
		}
	}
}