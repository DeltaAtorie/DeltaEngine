#include "stdafx.h"
#include "Opening.h"

#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalStorage/NumberStorage.h"
#include "Operation/Operation.h"
Opening::Opening()
{
	M_Level2D.Init("Assets/Sprite/Opening/Opening.casl", [&](Level2DRenderObjectData& objData)	
	{
		if (objData.EqualObjectName("WallPaper") == true)
		{
			M_WallTexture.Init("Assets/Sprite/Opening/WallPaper.DDS", 1920.0f, 1080.0f,true);
			M_WallPosition = objData.position;
			M_WallTexture.SetPosition(M_WallPosition);
			M_WallTexture.Update();
			return true;
		}
		if (objData.EqualObjectName("Switch") == true)
		{
			M_ButtonTexture.FadeInit("Assets/Sprite/Opening/Switch.DDS", "Assets/Sprite/Opening/SwitchOn.DDS",&M_Alfha, 75.0f, 75.0f);
			M_ButtonPosition = objData.position;
			M_ButtonTexture.SetPosition(M_ButtonPosition);
			M_ButtonTexture.Update();
			return true;
		}
	});
}
bool Opening::Start()
{
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	S_Element.P_Collision->DecisionDataSet(75, 75, M_ButtonPosition.x, M_ButtonPosition.y, COLLISION_BUTTON, TAG_NON);
	return true;
}
void Opening::Update()
{

}
void Opening::Render(RenderContext& rc)
{
	M_WallTexture.Draw(rc);
	M_ButtonTexture.Draw(rc);
}