#include "stdafx.h"
#include "MessageDialog.h"
#include "DimensionalStorage/HeaderStorage.h"
bool MessageDialog::Start()
{
	//S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	return true;
}
void MessageDialog::Init(int Number)
{
	M_WaitFlag = false;
}
void MessageDialog::Update()
{
	if (!M_WaitFlag)
	{


		DeleteGO(this);
	}
}