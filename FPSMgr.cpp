#include "FPSMgr.h"

FPSMgr::FPSMgr(int fps)
{
	timeBeginPeriod(1);

	mSampleNum = mFps = fps;

	mIntervalTime = 1000.0 / mFps;	//指定されたFPSのフレーム間の時間を取得する

	mFpsDrawInfo = 0.0f;

	mStartTime = mOldTime = timeGetTime();		//現在の時刻を記録する

	mCount = 0;
	
}

FPSMgr::~FPSMgr()
{
	timeEndPeriod(1);    // タイマーの精度を戻す
}

void FPSMgr::Update() {
	double now = timeGetTime();				//現在時刻を取得する
	double def = now - mOldTime;	//処理にかかった時間を求める

	//カウント数がサンプル数に達したらFPSを計算する
	if (mCount == mSampleNum) {
		mFpsDrawInfo = 1000.f / ((now - mStartTime) / (float)mSampleNum);
		mCount = 0;
		mStartTime = now;
	}

	//差分時間が待機時間より短ければ、その時間分待機する
	if (def < mIntervalTime) {	
		Sleep(mIntervalTime - def);	//処理を止める
	}
	mOldTime = now;					//時刻を更新する
	mCount++;
}

float FPSMgr::GetFPS()
{
	return mFpsDrawInfo;
}
