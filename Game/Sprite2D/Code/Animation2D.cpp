#include <string>
#include "stdafx.h"
#include "Animation2D.h"
Animation2D::~Animation2D()
{
	for (int i = 0 ; i < M_AnimationFrameLimit ; i++)
	{
		free((void*)M_TextureFilePath[i]);
	}
}
void Animation2D::Update()
{
	if (M_AnimationState == ANIMATION_PLAY)
	{
		M_Frame++;
		if (M_Frame > M_FrameLimit)
		{
			M_AnimationFrame++;
			if (M_AnimationFrame >= M_AnimationFrameLimit)
			{
				if (!M_LoopFlag)
				{
					DeleteGO(this);
				}else {
					M_AnimationFrame = 0;
				}
			}
			M_Frame = 0;
		}
		M_AnimationTexture.AnimationSet(M_AnimationFrame);
		M_AnimationTexture.SetPosition(M_AnimationPosition);
		M_AnimationTexture.Update();
	}
}
void Animation2D::Render(RenderContext& rc)
{
	if (M_AnimationState == ANIMATION_PLAY)
	{M_AnimationTexture.Draw(rc);}
}

void Animation2D::SetFilePath(const char* Sprite)
{
	for (int i = 0 ; i < M_AnimationFrameLimit ; i++)
	{
		strcpy(M_FilePath, Sprite);
		GetFileNumber(M_FilePath, i);
		M_TextureFilePath[i] = _strdup(M_FilePath);
	}
	M_AnimationTexture.AnimationInit(M_TextureFilePath , M_AnimationFrameLimit , M_Wide , M_Height);
}
void Animation2D::GetFileNumber(char* Word , int AnimationFrame)
{
	std::string SrtNumber = std::to_string(AnimationFrame);
	const char* FileNumber = SrtNumber.c_str();
	const char* Extension = ".DDS";
	char Text[15];

	strcpy(Text , FileNumber);
	strcat(Text , Extension);
	strcat(Word , Text);
	return;
}