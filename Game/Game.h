#pragma once
class Sprite2D;
class Data2D;
class Operation;

class GameActor;
class GameBackGround;
class GameOther;
class GameSprite;
class Game : public IGameObject
{
public:
	Game();
	~Game();
private:
	Sprite2D* P_Sprite2D   = nullptr;
	Data2D* P_Data2D       = nullptr;
	Operation* P_Operation = nullptr;

	GameActor* P_Actor           = nullptr;
	GameBackGround* P_BackGround = nullptr;
	GameOther* P_Other           = nullptr;
	GameSprite* P_Sprite         =nullptr;
};