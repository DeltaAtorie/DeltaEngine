#include <string>
#include <iostream>
#include "stdafx.h"
#include "DimensionalAnimation.h"
DimensionalAnimation::DimensionalAnimation()
{
	SetAnimation();
}
DimensionalAnimation::~DimensionalAnimation()
{
	for (int i = 0; i < M_AnimationFrameLimit; i++)
	{free((void*)M_TextureFilePath[i]);}
}
void DimensionalAnimation::Update()
{
	if (M_Animation != ANIMATION_NON)
	{
		M_Frame ++;
		if (M_Frame > M_FrameLimit)
		{
			M_AnimationFrame++;
			if (M_AnimationFrame >= M_AnimationFrameLimit)
			{
				M_AnimationFrame = 0;
			}
			M_Frame = 0;
		}
	}
	M_AnimationTexture.Update();
	M_AnimationTexture.AnimationSet(M_AnimationFrame);
}
void DimensionalAnimation::Render(RenderContext& rc)
{
	if (M_Animation != ANIMATION_NON)
	{
		M_AnimationTexture.Draw(rc);
	}
}

void DimensionalAnimation::SetAnimation()
{
	switch (M_Animation)
	{
	case ANIMATION_OPENING:
		M_AnimationFrameLimit = 3;
		SetFilePath();
		break;

	}
	M_AnimationTexture.AnimationInit(M_TextureFilePath, M_AnimationFrameLimit, 1920.0f, 1080.0);
}
void DimensionalAnimation::SetFilePath()
{
	for (int i = 0 ; i < M_AnimationFrameLimit ; i++)
	{
		GetFilePath(M_FilePath, M_Animation);
		GetFileNumber(M_FilePath, i);
		M_TextureFilePath[i] = _strdup(M_FilePath);
	}
}
void DimensionalAnimation::GetFilePath(char* Word, int Animation)
{
	switch (Animation)
	{
	case ANIMATION_OPENING:
		strcpy(Word, "Assets/Sprite/Animation/Animation");
		break;
	}
}
void DimensionalAnimation::GetFileNumber(char* Word, int AnimationFrame)
{
	std::string SrtNumber = std::to_string(AnimationFrame);
	const char* FileNumber = SrtNumber.c_str();
	const char* Extension = ".DDS";
	char Text[15];

	strcpy(Text, FileNumber);
	strcat(Text, Extension);
	strcat(Word, Text);
	return;
}