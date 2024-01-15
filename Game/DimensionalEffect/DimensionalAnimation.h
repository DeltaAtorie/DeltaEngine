#pragma once
class DimensionalAnimation : public IGameObject
{
public:
	DimensionalAnimation();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_AnimationTexture;
	const char* M_TextureFilePath      = nullptr;
	const char* M_TextureFileValuePath = nullptr;
	int M_AnimationFrame      = 0;
	int M_AnimationFrameLimit = 0;
	int M_Frame               = 0;
	int M_FrameLimit          = 60;
};

