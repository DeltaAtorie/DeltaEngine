#include "stdafx.h"
#include "Credit.h"
Credit::Credit()
{
	//M_Texture.PercentInit("Assets/Sprite/Percent/Player.DDS", "Assets/Sprite/Percent/Enemy.DDS", 0, 800.0f, 150.0f);
	//M_Texture.PercentInit("Assets/Sprite/Percent/a.DDS", "Assets/Sprite/Percent/b.DDS", 1, 1080.0f, 1080.0f);
	//M_Texture.PercentInit("Assets/Sprite/Percent/a.DDS", "Assets/Sprite/Percent/b.DDS", 2, 1920.0f, 1080.0f);
}
void Credit::Update()
{
	if (g_pad[0]->IsPress(enButtonRight))
	{
		M_Percent.x += 1.5 * g_gameTime->GetFrameDeltaTime();
		M_Percent.y -= 1.5 * g_gameTime->GetFrameDeltaTime();
	}
	if (g_pad[0]->IsPress(enButtonLeft))
	{
		M_Percent.x -= 1.5 * g_gameTime->GetFrameDeltaTime();
		M_Percent.y += 1.5 * g_gameTime->GetFrameDeltaTime();
	}
	M_Texture.Update();
	M_Texture.PercentSet(M_Percent);
}
void Credit::Render(RenderContext& rc)
{
	M_Texture.Draw(rc);
}
