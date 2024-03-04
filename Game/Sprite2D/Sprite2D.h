#pragma once
#include "Code/Animation2D.h"
#include "Code/Ending2D.h"
#include "Code/Opening2D.h"

class Animation2D;
class Ending2D;
class Opening2D;

enum class Sprite2DClass
{
	ANIMATION,
	ENDING,
	OPENING,
};

class Sprite2D : public IGameObject
{
public:
	void Sprite2DNewGO(Sprite2DClass Class)
	{
		switch (Class)
		{
		case Sprite2DClass::ANIMATION:
			P_Animation2D =
			NewGO<Animation2D>
			(0, "animation2d");
			break;
		case Sprite2DClass::ENDING:
			P_Ending2D =
			NewGO<Ending2D>
			(0, "ending2d");
			break;
		case Sprite2DClass::OPENING:
			P_Opening2D =
			NewGO<Opening2D>
			(0, "opening2d");
			break;
		}
	}

	void Sprite2DFindGO()
	{
		P_Ending2D =
		FindGO<Ending2D>
		("ending2d");

		P_Opening2D =
		FindGO<Opening2D>
		("opening2d");
	}

	void Sprite2DDeleteGO()
	{
		DeleteGO(P_Ending2D);
		DeleteGO(P_Opening2D);
	}
	void Sprite2DDeleteGO(Sprite2DClass Class)
	{
		switch (Class)
		{
		case Sprite2DClass::ANIMATION:
			DeleteGO(P_Animation2D);
			break;
		case Sprite2DClass::ENDING:
			DeleteGO(P_Ending2D);
			break;
		case Sprite2DClass::OPENING:
			DeleteGO(P_Opening2D);
			break;
		}
	}
public:
	Animation2D* P_Animation2D       = nullptr;
	Ending2D* P_Ending2D             = nullptr;
	Opening2D* P_Opening2D           = nullptr;
};
