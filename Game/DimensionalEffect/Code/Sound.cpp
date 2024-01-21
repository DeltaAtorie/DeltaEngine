#include "stdafx.h"
#include "Sound.h"
#include "sound/SoundEngine.h"
#include "DimensionalStorage/HeaderStorage.h"
Sound::Sound()
{
	g_soundEngine->ResistWaveFileBank(SE_START, "Assets/Sound/StartUp.wav");
}