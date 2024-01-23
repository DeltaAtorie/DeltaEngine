#pragma once
enum AnimationStorage
{
	ANIMATION_OPENING,
	ANIMATION_NON
};
class DimensionalAnimation : public IGameObject
{
public:
	DimensionalAnimation();
	void Update();
	void Render(RenderContext& rc);

	void SetAnimation(int Animation);
	void SetFilePath(int Animation);

	void GetFilePath(char* Word,int Animation);
	void GetFileNumber(char* Word,int AnimationFrame);
private:
	SpriteRender M_AnimationTexture;
	const char* M_TextureFilePath[256];
	const char* M_FilePath;
	int M_AnimationFrameLimit[256];
	int M_AnimationFrame      = 1;
	int M_Frame               = 0;
	int M_FrameLimit          = 30;
	int M_Animation           = ANIMATION_NON;
	char Word;
	bool Flag = true;
};

