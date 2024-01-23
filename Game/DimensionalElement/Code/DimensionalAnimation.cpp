#include <string>
#include "stdafx.h"
#include "DimensionalAnimation.h"
DimensionalAnimation::DimensionalAnimation()
{
	M_FilePath = "Assets/Sprite/Animation/Animation0.DDS";
}
void DimensionalAnimation::Update()
{
	/*for (int i = 0; i < 1; i++)
	{
		for (int j = 0; 1; j++)
		{
			Word = M_FilePath[j];
		}
	}*/
	if (M_Animation != ANIMATION_NON)
	{
		if (!Flag)
		{
			SetFilePath(ANIMATION_OPENING);
		}
		
		M_Frame++;
		if (M_Frame > M_FrameLimit)
		{
			M_Frame = 0;
			M_AnimationFrame++;

			if (M_AnimationFrame > M_AnimationFrameLimit[M_Animation])
			{M_AnimationFrame = 1;}
		}
		M_AnimationTexture.Update();
	}
}
void DimensionalAnimation::Render(RenderContext& rc)
{
	if (M_Animation != ANIMATION_NON)
	{M_AnimationTexture.Draw(rc);}
}

void DimensionalAnimation::SetAnimation(int Animation)
{
	switch (Animation)
	{
	case ANIMATION_OPENING:
		M_FilePath = "Assets/Sprite/Animation/Animation0.DDS";
		M_Animation = ANIMATION_OPENING;
		M_AnimationFrameLimit[M_Animation] = 3;
		SetFilePath(M_Animation);
		break;

	}
}
void DimensionalAnimation::SetFilePath(int Animation)
{
	for (int i = 0 ; i < M_AnimationFrameLimit[Animation] ; i++)
	{
		for (int j = 0 ; 1 ; j++)
		{
			char Word = M_FilePath[j];
		}
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
	int AnimationNumber = 65;
	std::string SrtNumber = std::to_string(AnimationNumber);
	const char* FileNumber = SrtNumber.c_str();
	const char* Extension = ".DDS";
	char Text[15];

	strcpy(Text, FileNumber);
	strcat(Text, Extension);
	strcat(Word, Text);
	return;
}


//const char* a[150];
//char c[256];
//strcpy(c, "Assets/Sprite/Animation/Animation");
//char d[256];
//strcpy(d, "0.DDS");
//
//int totalSize = strlen(c) + strlen(d) + 1;  // 1‚Í null •¶Žš‚Ì•ª
//a[0] = new char[totalSize];
//
//strcpy(const_cast<char*>(a[0]), c);
//strcat(const_cast<char*>(a[0]), d);
//
//printf("%s", a[0]);
//
//delete[] const_cast<char*>(a[0]);