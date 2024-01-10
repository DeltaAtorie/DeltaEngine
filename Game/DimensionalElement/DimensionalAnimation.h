#pragma once
class DimensionalAnimation : public IGameObject
{
public:
	DimensionalAnimation();
	void TextureSet(char* Sprite);
	void PositionSet(Vector3 Position)
	{M_AnimationPosition = Position;}
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_Animation;
	Vector3 M_AnimationPosition;
	char* M_Animations[16];
	int M_AnimationFrame = 0;
	int M_AnimationCount = 0;
};

