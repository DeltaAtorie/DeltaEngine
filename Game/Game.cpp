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

	Test.Init("Assets/Sprite/Frame.DDS", 1920.0f, 1080.0f);
	Test.Update();

	P_Data2D->P_Collision2D->CircleDataSet(10.0f , 10.0f , 10.0f , "Test1" , "Non");
	P_Data2D->P_Collision2D->CircleDataSet(10.0f , 20.0f , 20.0f , "Test2" , "Non");

	P_Data2D->P_Collision2D->SquareDataSet(100.0f,100.0f, 0.0f, 0.0f, "Test1", "Non");
	P_Data2D->P_Collision2D->SquareDataSet(100.0f,100.0f, 100.0f, 100.0f, "Test2", "Non");
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
void Game::Render(RenderContext& rc)
{
	if (P_Data2D->P_Collision2D->CircleAndCircle("Test1" , "Test2" , CrashType::BtoB))
	{Test.Draw(rc);}

	/*if (P_Data2D->P_Collision2D->SquareAndSquare("Test1", "Test2", CrashType::BtoB))
	{Test.Draw(rc);}*/
}