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
	void Render(RenderContext& rc);

	void SetLoadFile(int LoadFile)
	{
		M_LoadState = LOADSTATE_LOADING;
		M_LoadFile = LoadFile;
	}
	void Loading();
	void LoadComplete();
private:
	Level2DRender M_Level2D;
	SpriteRender M_LoadTexture;
	SpriteRender M_LoadCountTexture[3];
	SpriteRender M_LoadSymbolTexture;
	Vector2 M_LoadPercent = { 1.0f,0.0f };

	int M_LoadState    = LOADSTATE_NON;
	int M_LoadFile = LOADFILE_GAME;

	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
};

