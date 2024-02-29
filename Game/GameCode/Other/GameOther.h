#pragma once
#include "Code/GameCamera.h"

class GameCamera;

enum class OtherClass
{
	GAMECAMERA
};

class GameOther : public IGameObject
{
public:
	void OtherNewGO()
	{
		P_GameCamera =
		NewGO<GameCamera>
		(0, "gamecamera");
	}
	void OtherNewGO(OtherClass Class)
	{
		switch (Class)
		{
		case OtherClass::GAMECAMERA:
			P_GameCamera =
			NewGO<GameCamera>
			(0, "gamecamera");
			break;
		}
	}

	void OtherFindGO()
	{
		P_GameCamera =
		FindGO<GameCamera>
		("gamecamera");
	}

	void OtherDeleteGO()
	{
		DeleteGO(P_GameCamera);
	}
	void OtherDeleteGO(OtherClass Class)
	{
		switch (Class)
		{
		case OtherClass::GAMECAMERA:
			DeleteGO(P_GameCamera);
			break;
		}
	}
public:
	GameCamera* P_GameCamera = nullptr;
};