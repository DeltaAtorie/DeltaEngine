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
	ClassDimensionalElement S_Element;
	bool Flag = false;
};

