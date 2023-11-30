#include "stdafx.h"
#include "Game.h"
#include "GameCode/クレアエクション/ClairAction.h"

#include "Operation/Operation.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalElement/DimensionalElement.h"
Game::Game()
{
	S_GameCode.P_Clair = NewGO<ClairAction>(0, "clair");

	S_Operation.P_Mouse = NewGO<Mouse>(1, "mouse");
	S_Operation.P_Controller = NewGO<Controller>(1, "controller");

	S_Element.P_Camera = NewGO<DimensionalCamera>(1, "camera");
	S_Element.P_Collision = NewGO<DimensionalCollision>(1, "collision");
	S_Element.P_MapCreate = NewGO<MapCreate>(1, "create");
	
	S_Effect.P_Weather = NewGO<Weather>(1, "weather");
	S_Effect.P_Fade = NewGO<Fade>(1, "fade");
}
Game::~Game()
{
	DeleteGO(S_GameCode.P_Clair);

	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);

	DeleteGO(S_Element.P_Camera);
	DeleteGO(S_Element.P_Collision);
	DeleteGO(S_Element.P_MapCreate);

	DeleteGO(S_Effect.P_Weather);
	DeleteGO(S_Effect.P_Fade);
}