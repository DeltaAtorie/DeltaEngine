#include <string>
#include <iostream>
#include "stdafx.h"
#include "DimensionalAnimation.h"
DimensionalAnimation::~DimensionalAnimation()
{
	for (int i = 0; i < M_AnimationFrameLimit; i++)
	{free((void*)M_TextureFilePath[i]);}
}
void DimensionalAnimation::Update()
{
	if (M_AnimationState == ANIMATION_PLAY)
	{
		M_Frame++;
		if (M_Frame > M_FrameLimit)
		{
			M_AnimationFrame++;
			if (M_AnimationFrame >= M_AnimationFrameLimit)
			{M_AnimationFrame = 0;}
			M_Frame = 0;
		}
		M_AnimationTexture.AnimationSet(M_AnimationFrame);
		M_AnimationTexture.SetPosition(M_AnimationPosition);
		M_AnimationTexture.Update();
	}
}
void DimensionalAnimation::Render(RenderContext& rc)
{
	if (M_AnimationPower == ANIMATION_ON)
	{M_AnimationTexture.Draw(rc);}
}

void DimensionalAnimation::SetFilePath(const char* Sprite)
{
	for (int i = 0 ; i < M_AnimationFrameLimit ; i++)
	{
		strcpy(M_FilePath, Sprite);
		GetFileNumber(M_FilePath, i);
		M_TextureFilePath[i] = _strdup(M_FilePath);
	}
	M_AnimationTexture.AnimationInit(M_TextureFilePath, M_AnimationFrameLimit, 1920.0f, 1080.0);
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