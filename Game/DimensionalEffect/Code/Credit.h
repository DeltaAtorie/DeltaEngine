#pragma once
class Credit : public IGameObject
{
public:
	Credit();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender M_Texture;
	Vector2 M_Percent = { 0.2f,0.8f };
};

