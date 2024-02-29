#pragma once
#include "Code/Player.h"

class Player;

enum class ActorClass
{
	PLAYER
};

class GameActor : public IGameObject
{
public:
	void ActorNewGO()
	{
		P_Player =
		NewGO<Player>
		(0, "player");
	}
	void ActorNewGO(ActorClass Class)
	{
		switch (Class)
		{
		case ActorClass::PLAYER:
			P_Player =
			NewGO<Player>
			(0, "player");
			break;
		}
	}

	void ActorFindGO()
	{
		P_Player =
		FindGO<Player>
		("player");
	}

	void ActorDeleteGO()
	{
		DeleteGO(P_Player);
	}
	void ActorDeleteGO(ActorClass Class)
	{
		switch (Class)
		{
		case ActorClass::PLAYER:
			DeleteGO(P_Player);
			break;
		}
	}
public:
	Player* P_Player = nullptr;
};