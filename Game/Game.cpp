#include "stdafx.h"
#include "Game.h"
#include "Storage2D/Header2D.h"
Game::Game()
{
	P_Sprite2D  = NewGO<Sprite2D>(0 , "sprite2d");
	P_Data2D    = NewGO<Data2D>(0 , "data2d");
	P_Operation = NewGO<Operation>(0 , "operation");

	P_Actor      = NewGO<GameActor>(0 , "actor");
	P_BackGround = NewGO<GameBackGround>(0 , "background");
	P_Other      = NewGO<GameOther>(0 , "other");
	P_Sprite     = NewGO<GameSprite>(0 , "sprite");

	P_Data2D->Data2DNewGO();
	P_Operation->OperationNewGO();
}
Game::~Game()
{
	P_Sprite2D->Sprite2DDeleteGO();
	P_Data2D->Data2DDeleteGO();
	P_Operation->OperationDeleteGO();

	P_Actor->ActorDeleteGO();
	P_BackGround->BackGroundDeleteGO();
	P_Other->OtherDeleteGO();
	P_Sprite->SpriteDeleteGO();
}