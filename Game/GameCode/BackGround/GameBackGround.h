#pragma once
#include "Code/Skybox.h"
#include "Code/Stage.h"

class Skybox;
class Stage;

enum class BackGroundClass
{
	SKYBOX,
	STAGE
};

class GameBackGround : public IGameObject
{
public:
	void BackGroundNewGO()
	{
		P_Skybox =
		NewGO<Skybox>
		(0, "skybox");

		P_Stage =
		NewGO<Stage>
		(0, "stage");
	}
	void BackGroundNewGO(BackGroundClass Class)
	{
		switch (Class)
		{
		case BackGroundClass::SKYBOX:
			P_Skybox =
			NewGO<Skybox>
			(0, "skybox");
			break;
		case BackGroundClass::STAGE:
			P_Stage =
			NewGO<Stage>
			(0, "stage");
			break;
		}
	}

	void BackGroundFindGO()
	{
		P_Skybox =
		FindGO<Skybox>
		("skybox");

		P_Stage =
		FindGO<Stage>
		("stage");
	}

	void BackGroundDeleteGO()
	{
		DeleteGO(P_Skybox);
		DeleteGO(P_Stage);
	}
	void BackGroundDeleteGO(BackGroundClass Class)
	{
		switch (Class)
		{
		case BackGroundClass::SKYBOX:
			DeleteGO(P_Skybox);
			break;
		case BackGroundClass::STAGE:
			DeleteGO(P_Stage);
			break;
		}
	}
public:
	Skybox* P_Skybox = nullptr;

	Stage* P_Stage = nullptr;
};

