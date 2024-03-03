#pragma once
#include "Storage2D/Utility2D.h"

class Sprite2D;
class Data2D;
class Actor;
class GameActor;
class GameBackGround;
class GameOther;
class GameSprite;

enum class LoadState
{
	LOADING,
	LOADCOMPLETE,
	NON
};
enum class LoadFile
{
	GAME,
	NON
};
class Load2D : public IGameObject
{
public:
	Load2D() : S_Percent(1.0f , 0.0f , 0.8f) {};
	~Load2D();
	bool Start();
	void Update();

	//ロード開始
	void SetFileLoad(LoadFile LoadFile)
	{
		M_LoadFile  = LoadFile;
		M_LoadState = LoadState::LOADING;
	
	}
	//ロード終了
	void ResetFileLoad()
	{
		S_Percent.PercentReset();
		M_LoadState = LoadState::NON;
	}
	//ロード取得
	float GetLoadPercent()
	{return S_Percent.GetPercent();}
	//ロード中
	void Loading();
	void FileLoad();
	void FileDelete();
private:
	LoadState M_LoadState = LoadState::NON;
	LoadFile M_LoadFile   = LoadFile::GAME;

	Percent S_Percent;

	Sprite2D* P_Sprite2D         = nullptr;
	Data2D* P_Data2D             = nullptr;
	GameActor* P_Actor           = nullptr;
	GameBackGround* P_BackGround = nullptr;
	GameOther* P_Other           = nullptr;
	GameSprite* P_Sprite         = nullptr;

	LPCWSTR FilePath;
	HANDLE HandleFile;
	DWORD FileSize;
};

