#pragma once
class CurrentTime : public IGameObject
{
public:
	void Update();
	int GetHour()
	{return M_Hour;}
	int GetMinute()
	{return M_Minute;}
	int GetSecond()
	{return M_Second;}
private:
	SYSTEMTIME M_CurrentTime;
	int M_Hour   = 0;
	int M_Minute = 0;
	int M_Second = 0;
};

