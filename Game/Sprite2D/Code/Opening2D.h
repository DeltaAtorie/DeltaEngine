#pragma once
#include "Storage2D/Utility2D.h"
#include "level2D/Level2DRender.h"
class Sprite2D;
class Data2D;
class Operation;
class Opening2D : public IGameObject
{
public:
	Opening2D();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	Sprite2D* P_Sprite2D = nullptr;
	Data2D* P_Data2D = nullptr;
	Operation* P_Operation = nullptr;
};

