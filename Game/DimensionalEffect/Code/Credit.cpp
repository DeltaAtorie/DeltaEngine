#include "stdafx.h"
#include "Credit.h"
#include <cstdlib>
Credit::Credit()
{
	srand(static_cast<unsigned int>(time(nullptr))); // ‰Šú‰»‚ğ‰ü‘P‚·‚é‚½‚ß‚ÉtimeŠÖ”‚ğg—p
	for (int i = 0; i < 15; i++)
	{
		float randomValue = (float)(rand() % 1921 - 960);
		Position[i].x = randomValue;

		Texture[i].TestInit("Assets/Sprite/Test/Test.DDS", 10.0f, 1080.0f);
		Texture[i].SetPosition(Position[i]);
		Texture[i].Update();
	}
}
bool Credit::Start()
{
	return true;
}
void Credit::Update()
{
	Percent += 0.05;
	if (Percent > 1.0f)
	{
		Percent = 0.0f;
	}
	for (int i = 0; i < 15; i++)
	{
		Texture[i].TestSet(Percent);
		Texture[i].Update();
	}
}
void Credit::Render(RenderContext& rc)
{
	for (int i = 0; i < 15; i++)
	{
		Texture[i].Draw(rc);
	}
}
