#pragma once
#include <Windows.h>
#include <mmsystem.h>

class FPSMgr2
{
private:
	int mStartTime;
	int mOldTime;
	int mCount;
	float mFps;
	int FPS;
	float mDeltaTime;
public:
	FPSMgr2(int fps);
	~FPSMgr2();

	void Update();
	void Wait();
	float GetFPS();
	float GetDeltaTime();
};

