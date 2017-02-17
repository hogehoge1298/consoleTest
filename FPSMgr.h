#pragma once
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <mmsystem.h>

class FPSMgr
{
public:
	FPSMgr(int fps);
	~FPSMgr();

	void Update();
	float GetFPS();
private:
	float mIntervalTime;	//処理を止める時間
	double mOldTime;		//前回の時間
	double mStartTime;		//FPS計算用の開始時間記録変数
	int mFps;			//固定するFPS
	int mSampleNum;		//サンプルを記録する数
	int mCount;			//サンプル回数回したかどうかのカウンタ
	float mFpsDrawInfo;	//表示用のFPS
};

