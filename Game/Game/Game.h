#pragma once
#include "DimensionalStorage/StructStorage.h"
class Game : public IGameObject
{
public:
	Game();
	~Game();
private:
	ClassGameCode S_GameCode;
	ClassOperation S_Operation;
	ClassDimensionalEffect S_Effect;
	ClassDimensionalElement S_Element;
};

