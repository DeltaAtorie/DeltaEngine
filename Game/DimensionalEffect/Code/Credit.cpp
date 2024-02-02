#include "stdafx.h"
#include "Credit.h"
Credit::Credit()
{
	
}
bool Credit::Start()
{
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, -480.0f, 0.0f, 10, 0);
	S_Element.P_Collision->DecisionDataSet(960.0f, 1080.0f, 480.0f, 0.0f, 11, 0);
	return true;
}
void Credit::Update()
{
	Flag = S_Element.P_Collision->DecisionAndDecisionCollision(10, 11);
}
void Credit::Render(RenderContext& rc)
{
	
}
