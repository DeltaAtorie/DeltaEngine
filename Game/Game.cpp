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

	Test1.Init("Assets/Sprite/Test1.DDS", 150.0f, 150.0f);
	Test1.SetPosition(Position1);
	Test1.Update();

	Test2.Init("Assets/Sprite/Test2.DDS", 150.0f, 150.0f);
	Test2.SetPosition(Position2);
	Test2.Update();

	P_Data2D->P_Collision2D->CircleDataSet(75.0f , Position1.x , Position1.y , "Test1" , "Non");
	P_Data2D->P_Collision2D->CircleDataSet(75.0f , Position2.x , Position2.y , "Test2" , "Non");

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

void Game::Update()
{
	
	if (g_pad[0]->IsPress(enButtonUp))
	{
		Position1.y += 0.5f;
	}
	if (g_pad[0]->IsPress(enButtonDown))
	{
		Position1.y -= 0.5f;
	}
	if (g_pad[0]->IsPress(enButtonRight))
	{
		Position1.x += 0.5f;
	}
	if (g_pad[0]->IsPress(enButtonLeft))
	{
		Position1.x -= 0.5f;
	}


	P_Data2D->P_Collision2D->CircleSetPosition(Position1.x, Position1.y, "Test1");
	Test1.SetPosition(Position1);
	Test1.Update();

	P_Data2D->P_Collision2D->CircleSetPosition(Position2.x, Position2.y, "Test2");
	Test2.SetPosition(Position2);
	Test2.Update();
}
void Game::Render(RenderContext& rc)
{
	if (P_Data2D->P_Collision2D->CircleAndCircle("Test1" , "Test2" , CrashType::BtoB))
	{Test.Draw(rc);}

	Test1.Draw(rc);
	Test2.Draw(rc);
}