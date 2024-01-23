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
	~DimensionalAnimation();
	void Update();
	void Render(RenderContext& rc);

	void SetAnimation();
	void SetFilePath();

	void GetFilePath(char* Word,int Animation);
	void GetFileNumber(char* Word,int AnimationFrame);
private:
	SpriteRender M_AnimationTexture;
	const char* M_TextureFilePath[256];
	char M_FilePath[256];
	int M_AnimationFrameLimit = 0;
	int M_AnimationFrame      = 0;
	int M_Frame               = 0;
	int M_FrameLimit          = 30;
	int M_Animation           = ANIMATION_OPENING;
	char Word;
};

