#include "stdafx.h"
#include "CurrentTime.h"
void CurrentTime::Update()
{
	M_Hour   = M_CurrentTime.wHour;
	M_Minute = M_CurrentTime.wMinute;
	M_Second = M_CurrentTime.wSecond;
}