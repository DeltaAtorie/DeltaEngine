#pragma once
#include "DimensionalStorage/HeaderStorage.h"
class Credit : public IGameObject
{
public:
	Credit();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	SpriteRender Texture[15];
	Vector3 Position[15];
	float Percent;
};

