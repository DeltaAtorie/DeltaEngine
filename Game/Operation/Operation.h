#pragma once
#include "Code/Controller.h"
#include "Code/Mouse.h"

class Mouse;
class Controller;
class Operation : public IGameObject
{
public:
	void OperationNewGO()
	{
		P_Mouse      = NewGO<Mouse>(3, "mouse");
		P_Controller = NewGO<Controller>(3, "controller");
	}
	void OperationFindGO()
	{
		P_Mouse      = FindGO<Mouse>("mouse");
		P_Controller = FindGO<Controller>("controller");
	}
	void OperationDeleteGO()
	{
		DeleteGO(P_Mouse);
		DeleteGO(P_Controller);
	}
public:
	Mouse* P_Mouse           = nullptr;
	Controller* P_Controller = nullptr;
};