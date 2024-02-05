#pragma once
#include "DimensionalStorage/HeaderStorage.h"
#include "level2D/Level2DRender.h"
enum
{
	LOADSTATE_LOADING,//ロード中
	LOADSTATE_LOADCOMPLETE,//ロード完成
	LOADSTATE_NON
};
enum
{
	LOADFILE_GAME,//ロード中
	LOADFILE_NON
};
class Load : public IGameObject
{
public:
	bool Start();
	void Update();

	void LoadFileInit();
	void SetLoadFile(int LoadFile)
	{
		M_LoadState = LOADSTATE_LOADING;
		M_LoadFile = LoadFile;
		LoadFileInit();
	}
	void Loading();

	bool GetLoading()
	{
		if (M_LoadState == LOADSTATE_LOADING)
		{
			return true;
		}else {
			return false;
		}
	}
	bool GetLoadComplete()
	{
		if (M_LoadState == LOADSTATE_LOADCOMPLETE)
		{
			return true;
		}else {
			return false;
		}
	}
	Vector2 GetLoadPercent()
	{
		return M_LoadPercent;
	}
private:
	Vector2 M_LoadPercent = { 1.0f,0.0f };

	int M_LoadState    = LOADSTATE_NON;
	int M_LoadFile = LOADFILE_GAME;

	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;

	LPCWSTR FilePath;
	HANDLE HandleFile;
	DWORD FileSize;
};

