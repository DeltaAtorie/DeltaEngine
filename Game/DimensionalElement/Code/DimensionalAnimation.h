#pragma once
enum AnimationStorage
{
	ANIMATION_ON,
	ANIMATION_OFF,
	ANIMATION_PLAY,
	ANIMATION_STOP,
};
class DimensionalAnimation : public IGameObject
{
public:
	~DimensionalAnimation();
	void Update();
	void Render(RenderContext& rc);

	void InitAnimation(const char* Sprite , int AnimationFrameLimit , int FrameLimit)
	{

		M_AnimationFrameLimit = AnimationFrameLimit;
		M_FrameLimit          = FrameLimit;
		M_AnimationPower      = ANIMATION_ON;
		M_AnimationState      = ANIMATION_PLAY;

		SetFilePath(Sprite);
	}
	void SetPosition(Vector3 Position)
	{M_AnimationPosition = Position;}
	void SetFilePath(const char* Sprite);
	void GetFileNumber(char* Word,int AnimationFrame);

	void PowerOn()
	{M_AnimationPower = ANIMATION_ON;}
	void PowerOff()
	{M_AnimationPower = ANIMATION_OFF;}
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
	int M_AnimationPower      = ANIMATION_OFF;
	int M_AnimationState      = ANIMATION_STOP;
};

