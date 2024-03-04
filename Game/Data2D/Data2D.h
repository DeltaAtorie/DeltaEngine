#pragma once
#include "Code/Camera2D.h"
#include "Code/Collision2D.h"
#include "Code/Helper2D.h"
#include "Code/Load2D.h"
#include "Code/Sound2D.h"

class Camera2D;
class Collision2D;
class Helper2D;
class Load2D;
class Sound2D;

enum class Data2DClass
{
	CAMERA,
	COLLISION,
	HELPER,
	LOAD,
	SOUND,
};

class Data2D : public IGameObject
{
public:
	void Data2DNewGO()
	{
		P_Camera2D =
		NewGO<Camera2D>
		(0, "camera2d");

		P_Collision2D =
		NewGO<Collision2D>
		(0, "collision2d");

		P_Helper2D =
		NewGO<Helper2D>
		(0, "helper2d");

		P_Load2D =
		NewGO<Load2D>
		(0, "load2d");

		P_Sound2D =
		NewGO<Sound2D>
		(0, "sound2d");
	}
	void Data2DNewGO(Data2DClass Class)
	{
		switch (Class)
		{
		case Data2DClass::CAMERA:
			P_Camera2D =
			NewGO<Camera2D>
			(0, "camera2d");
			break;
		case Data2DClass::COLLISION:
			P_Collision2D =
			NewGO<Collision2D>
			(0, "collision2d");
			break;
		case Data2DClass::HELPER:
			P_Helper2D =
			NewGO<Helper2D>
			(0, "helper2d");
			break;
		case Data2DClass::LOAD:
			P_Load2D =
			NewGO<Load2D>
			(0, "load2d");
			break;
		case Data2DClass::SOUND:
			P_Sound2D =
			NewGO<Sound2D>
			(0, "sound2d");
			break;
		}
	}
	
	void Data2DFindGO()
	{
		P_Camera2D =
		FindGO<Camera2D>
		("camera2d");

		P_Collision2D =
		FindGO<Collision2D>
		("collision2d");

		P_Helper2D =
		FindGO<Helper2D>
		("helper2d");

		P_Load2D =
		FindGO<Load2D>
		("load2d");

		P_Sound2D =
		FindGO<Sound2D>
		("sound2d");
	}

	void Data2DDeleteGO()
	{
		DeleteGO(P_Camera2D);
		DeleteGO(P_Collision2D);
		DeleteGO(P_Helper2D);
		DeleteGO(P_Load2D);
		DeleteGO(P_Sound2D);
	}
	void Data2DDeleteGO(Data2DClass Class)
	{
		switch (Class)
		{
		case Data2DClass::CAMERA:
			DeleteGO(P_Camera2D);
			break;
		case Data2DClass::COLLISION:
			DeleteGO(P_Collision2D);
			break;
		case Data2DClass::HELPER:
			DeleteGO(P_Helper2D);
			break;
		case Data2DClass::LOAD:
			DeleteGO(P_Load2D);
			break;
		case Data2DClass::SOUND:
			DeleteGO(P_Sound2D);
			break;
		}
	}
public:
	Camera2D* P_Camera2D = nullptr;

	Collision2D* P_Collision2D = nullptr;

	Helper2D* P_Helper2D = nullptr;

	Load2D* P_Load2D = nullptr;

	Sound2D* P_Sound2D = nullptr;
};