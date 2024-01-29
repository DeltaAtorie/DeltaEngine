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
class Helper;
class MapCreate;
struct ClassDimensionalElement
{
	DimensionalAnimation* P_Animation = nullptr;
	DimensionalCamera* P_Camera       = nullptr;
	DimensionalCollision* P_Collision = nullptr;
	Helper* P_Helper                  = nullptr;
	MapCreate* P_MapCreate            = nullptr;
};

class Credit;
class Opening;
class Weather;
class Fade;
class Sound;
class MessageDialog;
class ScreenChange;
class Load;
struct ClassDimensionalEffect
{
	Credit* P_Credit                  = nullptr;
	Opening* P_Opening                = nullptr;
	Weather* P_Weather                = nullptr;
	Fade* P_Fade                      = nullptr;
	Sound* P_Sound                    = nullptr;
	MessageDialog* P_Message          = nullptr;
	ScreenChange* P_Screen            = nullptr;
	Load* P_Load                      = nullptr;
};