#pragma once
struct Sprite : public IGameObject
{
public:
	void Init(const char* Texture)
	{
		
	}
private:
	SpriteRender M_Sprite;
	float M_Wide   = 0.0f;
	float M_Height = 0.0f;
};
struct Percent : public IGameObject
{
public:
	Percent(float UpLimit, float LowerLimit, float Speed)
	{
		M_PercentUpperLimit = UpLimit;
		M_PercentLowerLimit = LowerLimit;
		M_PercentSpeed = Speed;
	}
	void PercentReset()
	{M_Percent = 0.0f;}
	
	float GetPercent()
	{return M_Percent;}
	float GetUpeer()
	{return M_PercentUpperLimit;}
	float GetLower()
	{return M_PercentLowerLimit;}
	float GetSpeed()
	{return M_PercentSpeed;}

	void Increase()
	{M_Percent += M_PercentSpeed * g_gameTime->GetFrameDeltaTime();}
	void Decrease()
	{M_Percent -= M_PercentSpeed * g_gameTime->GetFrameDeltaTime();}

	void Increase(float Number)
	{M_Percent += Number;}
	void Decrease(float Number)
	{M_Percent -= Number;}

	void Increment()
	{M_Percent += 0.1f;}
	void Decrement()
	{M_Percent -= 0.1f;}

	bool OverflowUp()
	{
		if (M_Percent >= M_PercentUpperLimit)
		{
			M_Percent = M_PercentUpperLimit;
			return true;
		}
		return false;
	}
	bool OverflowDown()
	{
		if (M_Percent <= M_PercentLowerLimit)
		{
			M_Percent = M_PercentLowerLimit;
			return true;
		}
		return false;
	}

	void Update()
	{
		OverflowUp();
		OverflowDown();
	}
private:
	float M_Percent           = 0.0f;
	float M_PercentUpperLimit = 0.0f;
	float M_PercentLowerLimit = 0.0f;
	float M_PercentSpeed      = 0.0f;
};
struct CoolFlag : public IGameObject
{
public:
	CoolFlag(float TimeLimit, float TimeSpeed)
	{
		M_CoolTimeLimit = TimeLimit;
		M_CoolTimeSpeed = TimeSpeed;
	}
	void Update()
	{
		if (!M_Flag)
		{
			M_CoolTime += M_CoolTimeSpeed * g_gameTime->GetFrameDeltaTime();
			if (M_CoolTime > M_CoolTimeLimit)
			{
				M_Flag = true;
				M_CoolTime = 0.0f;
			}
		}
	}
	bool GetFlag()
	{
		if (M_Flag)
		{
			M_Flag = false;
			return true;
		}
		return false;
	}
	float Get()
	{return M_CoolTime;}
private:
	bool M_Flag           = true;
	float M_CoolTime      = 0.0f;
	float M_CoolTimeLimit = 0.0f;
	float M_CoolTimeSpeed = 0.0f;
};