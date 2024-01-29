#include "stdafx.h"
#include "Game.h"
#include "DimensionalStorage/HeaderStorage.h"
Game::Game()
{
	//S_Element.P_Animation = NewGO<DimensionalAnimation>(2, "animation");
	//S_Element.P_Camera    = NewGO<DimensionalCamera>(1, "camera");
	S_Element.P_Collision = NewGO<DimensionalCollision>(1, "collision");
	S_Element.P_Helper    = NewGO<Helper>(1, "helper");
	S_Element.P_MapCreate = NewGO<MapCreate>(1, "create");
	
	//S_Effect.P_Credit = NewGO<Credit>(6, "credit");
	
	//S_Effect.P_Opening = NewGO<Opening>(2, "opening");
	//S_Effect.P_Weather = NewGO<Weather>(1, "weather");
	S_Effect.P_Fade = NewGO<Fade>(4, "fade");
	S_Effect.P_Sound = NewGO<Sound>(1, "sound");
	S_Effect.P_Screen = NewGO<ScreenChange>(3,"screen");
	
	S_Operation.P_Mouse = NewGO<Mouse>(3, "mouse");
	S_Operation.P_Controller = NewGO<Controller>(3, "controller");

	//S_Effect.P_Fade->StartFadeIn();
}
Game::~Game()
{
	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);

	DeleteGO(S_Element.P_Camera);
	DeleteGO(S_Element.P_Collision);
	DeleteGO(S_Element.P_MapCreate);

	DeleteGO(S_Effect.P_Weather);
	DeleteGO(S_Effect.P_Fade);
}