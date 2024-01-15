#pragma once
class ClairAction;

struct ClassGameCode
{
	ClairAction* P_Clair = nullptr;
};

class Mouse;
class Controller;
struct ClassOperation
{
	Mouse* P_Mouse           = nullptr;
	Controller* P_Controller = nullptr;
};

class DimensionalCamera;
class DimensionalCollision;
class MapCreate;
struct ClassDimensionalElement
{
	
	DimensionalCamera* P_Camera       = nullptr;
	DimensionalCollision* P_Collision = nullptr;
	MapCreate* P_MapCreate            = nullptr;
};

class DimensionalAnimation;
class Opening;
class Weather;
class Fade;
class Sound;
struct ClassDimensionalEffect
{
	DimensionalAnimation* P_Animation = nullptr;
	Opening* P_Opening = nullptr;
	Weather* P_Weather = nullptr;
	Fade* P_Fade       = nullptr;
	Sound* P_Sound     = nullptr;
};