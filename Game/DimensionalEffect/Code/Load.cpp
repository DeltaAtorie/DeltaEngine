#include "stdafx.h"
#include "Load.h"
#include "DimensionalStorage/HeaderStorage.h"
bool Load::Start()
{
	S_Element.P_Helper = FindGO<Helper>("helper");
	return true;
}
void Load::Update()
{
	switch (M_LoadState)
	{
	case LOADSTATE_LOADING:
		Loading();
		break;
	}
	int Percent = (int)(M_LoadPercent.y * 100);
}
void Load::LoadFileInit()
{
	
}

void Load::Loading()
{
	if (M_LoadPercent.x > 0.0f && M_LoadPercent.y < 1.0f)
	{
		FilePath = L"Assets/Sprite/Load/LogoOn.DDS";
		HandleFile = CreateFile(FilePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		FileSize = GetFileSize(HandleFile, NULL);
		M_LoadPercent.x -= 1.0f / 90.0f;
		M_LoadPercent.y += 1.0f / 90.0f;
	}else {
		M_LoadPercent = { 0.0f,1.0f };
		M_LoadState = LOADSTATE_LOADCOMPLETE;
		CloseHandle(HandleFile);
	}
}