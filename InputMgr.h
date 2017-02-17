#pragma once

#include <Windows.h>

class InputMgr
{
private:
	BYTE mKbdState[256];

public:
	InputMgr();
	~InputMgr();
	
	bool UpdateKeyboadState();
	float GetHorizontal();
	float GetVertical();
};

