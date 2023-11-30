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

class DimensionalAnimation;
class DimensionalCamera;
class DimensionalCollision;
class MapCreate;
struct ClassDimensionalElement
{
	DimensionalAnimation* P_Animation = nullptr;
	DimensionalCamera* P_Camera       = nullptr;
	DimensionalCollision* P_Collision = nullptr;
	MapCreate* P_MapCreate            = nullptr;
};

class Weather;
class Fade;
struct ClassDimensionalEffect
{
	Weather* P_Weather = nullptr;
	Fade* P_Fade       = nullptr;
};