#pragma once
#include "Code/Animation2D.h"
#include "Code/Ending2D.h"
#include "Code/Opening2D.h"
#include "Code/OptionSprite2D.h"
#include "Code/ScreenChange2D.h"

class Animation2D;
class Ending2D;
class Opening2D;
class OptionSprite2D;
class ScreenChange2D;

enum class Sprite2DClass
{
	ANIMATION,
	ENDING,
	OPENING,
	OPTIONSPRITE,
	SCREENCHANGE,
};

class Sprite2D : public IGameObject
{
public:
	void Sprite2DNewGO()
	{
		P_Opening2D =
		NewGO<Opening2D>
		(0, "opening2d");

		P_OptionSprite2D =
		NewGO<OptionSprite2D>
		(0, "optionsprite2d");

		P_ScreenChange2D =
		NewGO<ScreenChange2D>
		(2, "ScreenChange2d");
	}
	void Data2DNewGO(Sprite2DClass Class)
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
		case Sprite2DClass::OPTIONSPRITE:
			P_OptionSprite2D =
			NewGO<OptionSprite2D>
			(0, "optionsprite2d");
			break;
		case Sprite2DClass::SCREENCHANGE:
			P_ScreenChange2D =
			NewGO<ScreenChange2D>
			(2, "ScreenChange2d");
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

		P_OptionSprite2D =
		FindGO<OptionSprite2D>
		("optionsprite2d");

		P_ScreenChange2D =
		FindGO<ScreenChange2D>
		("ScreenChange2d");
	}

	void Sprite2DDeleteGO()
	{
		DeleteGO(P_Ending2D);
		DeleteGO(P_Opening2D);
		DeleteGO(P_OptionSprite2D);
		DeleteGO(P_ScreenChange2D);
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
		case Sprite2DClass::OPTIONSPRITE:
			DeleteGO(P_OptionSprite2D);
			break;
		case Sprite2DClass::SCREENCHANGE:
			DeleteGO(P_ScreenChange2D);
			break;
		}
	}
public:
	Animation2D* P_Animation2D       = nullptr;

	Ending2D* P_Ending2D             = nullptr;

	Opening2D* P_Opening2D           = nullptr;

	OptionSprite2D* P_OptionSprite2D = nullptr;

	ScreenChange2D* P_ScreenChange2D = nullptr;
};
