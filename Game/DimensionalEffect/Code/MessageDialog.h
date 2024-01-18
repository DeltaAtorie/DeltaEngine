#pragma once
#include "DimensionalStorage/StructStorage.h"
#include "level2D/Level2DRender.h"
class MessageDialog : public IGameObject
{
public:
	bool Start();
	void Init(int Number);
	void Update();
private:
	Level2DRender M_Level2D;
	bool M_WaitFlag = true;

	ClassDimensionalElement S_Element;
	enum MessageButton
	{

	};
};

