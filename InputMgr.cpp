#include "InputMgr.h"



InputMgr::InputMgr()
{
}


InputMgr::~InputMgr()
{
}



bool InputMgr::UpdateKeyboadState()
{
	if (!GetKeyboardState(mKbdState)) {
		float result = 0;
	}

	return true;
}

float InputMgr::GetHorizontal()
{
	float result = 0.0f;

	/*if (mKbdState[VK_LEFT] & 0x80){
		result = -1.0f;
	}
	if (mKbdState[VK_RIGHT] & 0x80)
	{
		result = 1.0f;
	}*/

	if (GetAsyncKeyState(VK_LEFT))
	{
		result = -1.0f;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		result = 1.0f;
	}
	return result;
}

float InputMgr::GetVertical()
{
	float result = 0.0f;

	if (GetAsyncKeyState(VK_UP)) {
		result = -1.0f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		result = 1.0f;
	}
	return result;
}
