#include "FPSMgr2.h"



FPSMgr2::FPSMgr2(int fps)
{
	mStartTime = 0;
	mCount = 0;
	FPS = fps;
	mFps = 0;
	timeBeginPeriod(1);
	mDeltaTime = 0.0f;
}


FPSMgr2::~FPSMgr2()
{
	timeEndPeriod(1);
}


void FPSMgr2::Update() {
	if (mCount == 0) {
		mStartTime = timeGetTime();
		mOldTime = timeGetTime();
	}

	mDeltaTime = (timeGetTime() - mOldTime) / 1000.0f;


	if (mCount == FPS) {
		int t = timeGetTime();
		mFps = 1000.f / ((t - mStartTime) / (float)FPS);
		mCount = 0;
		mStartTime = t;
	}

	mOldTime = timeGetTime();
	mCount++;
}

void FPSMgr2::Wait() {
	int tookTime = timeGetTime() - mStartTime;
	int waitTime = mCount * 1000 / FPS - tookTime;
	//mDeltaTime = tookTime / mCount / 1000.f;
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}

float FPSMgr2::GetFPS()
{
	return mFps;
}

float FPSMgr2::GetDeltaTime()
{
	return mDeltaTime;
}
