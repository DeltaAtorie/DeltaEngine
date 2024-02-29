#pragma once
enum AnimationStorage
{
	ANIMATION_PLAY,
	ANIMATION_STOP,
};
class Animation2D : public IGameObject
{
public:
	~Animation2D();
	void Update();
	void Render(RenderContext& rc);

	void AnimationInit(const char* Sprite , float Wide , float Height , int AnimationFrameLimit , int FrameLimit , Vector3 Position = { 0.0f , 0.0f , 0.0f } , bool Loop = false)
	{
		M_Wide                = Wide;
		M_Height              = Height;
		M_AnimationFrameLimit = AnimationFrameLimit;
		M_FrameLimit          = FrameLimit;
		M_AnimationPosition   = Position;
		M_LoopFlag            = Loop;
		M_AnimationState      = ANIMATION_PLAY;
		SetFilePath(Sprite);
	}
	void SetFilePath(const char* Sprite);
	void GetFileNumber(char* Word , int AnimationFrame);

	void Play()
	{M_AnimationState = ANIMATION_PLAY;}
	void Stop()
	{M_AnimationState = ANIMATION_STOP;}
private:
	SpriteRender M_AnimationTexture;
	Vector3 M_AnimationPosition;

	const char* M_TextureFilePath[256];
	char M_FilePath[256];

	int M_AnimationFrameLimit = 0;
	int M_AnimationFrame      = 0;
	int M_Frame               = 0;
	int M_FrameLimit          = 0;
	int M_AnimationState      = ANIMATION_STOP;
	bool M_LoopFlag           = false;
	float M_Wide              = 0.0f;
	float M_Height            = 0.0f;
};

