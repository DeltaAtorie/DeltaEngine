#pragma once
class Helper : public IGameObject
{
public:

	void ForwardAlphaUpdate(Vector2& Alpha, float Speed)
	{
		Alpha.x += Speed * g_gameTime->GetFrameDeltaTime();
		Alpha.y -= Speed * g_gameTime->GetFrameDeltaTime();
	}
	void ReverseAlphaUpdate(Vector2& Alpha, float Speed)
	{
		Alpha.x -= Speed * g_gameTime->GetFrameDeltaTime();
		Alpha.y += Speed * g_gameTime->GetFrameDeltaTime();
	}
private:
};

