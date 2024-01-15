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

	void SetAnimationFrame(int Animation);

	void GetFilePath();
	void GetOpening();
private:
	SpriteRender M_AnimationTexture;
	const char* M_TextureFilePath       = nullptr;
	const char* M_TextureFileMemoryPath = nullptr;
	int M_AnimationFrame      = 1;
	int M_AnimationFrameLimit = 0;
	int M_Frame               = 0;
	int M_FrameLimit          = 30;
	int M_Animation           = ANIMATION_NON;
};

