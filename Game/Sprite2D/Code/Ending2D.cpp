#include "stdafx.h"
#include "Ending2D.h"
#include "Storage2D/Header2D.h"
bool Ending2D::Start()
{
	P_Sprite2D = FindGO<Sprite2D>("sprite2d");
	P_Sprite2D->Sprite2DFindGO();

	P_Data2D = FindGO<Data2D>("data2d");
	P_Data2D->Data2DFindGO();

	P_Operation = FindGO<Operation>("operation");
	P_Operation->OperationFindGO();

	return true;
}
void Ending2D::Update()
{

}
void Ending2D::Render(RenderContext& rc)
{

}