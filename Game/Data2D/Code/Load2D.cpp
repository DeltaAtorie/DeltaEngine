#include "stdafx.h"
#include "Load2D.h"
#include "Storage2D/Header2D.h"
Load2D::~Load2D()
{
	CloseHandle(HandleFile);
}
bool Load2D::Start()
{
	P_Sprite2D = FindGO<Sprite2D>("sprite2d");
	P_Sprite2D->Sprite2DFindGO();

	P_Data2D = FindGO<Data2D>("data2d");
	P_Data2D->Data2DFindGO();

	P_Sprite = FindGO<GameSprite>("sprite");
	P_Sprite->SpriteFindGO();

	return true;
}
void Load2D::Update()
{
	switch (M_LoadState)
	{
	case LoadState::LOADING:
		Loading();
		break;
	}
	S_Percent.Update();
}

void Load2D::Loading()
{
	if (!S_Percent.OverflowUp())
	{
		S_Percent.Increase();
	}else {
		if (S_Percent.OverflowUp())
		{
			FileDelete();
			FileLoad();
			M_LoadFile  = LoadFile::NON;
			M_LoadState = LoadState::LOADCOMPLETE;
		}
	}
}
void Load2D::FileLoad()
{
	switch (M_LoadFile)
	{
	case LoadFile::GAME:
		break;
	}
}
void Load2D::FileDelete()
{
	switch (M_LoadFile)
	{
	case LoadFile::GAME:
		break;
	}
}