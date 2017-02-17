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
	float mIntervalTime;	//�������~�߂鎞��
	double mOldTime;		//�O��̎���
	double mStartTime;		//FPS�v�Z�p�̊J�n���ԋL�^�ϐ�
	int mFps;			//�Œ肷��FPS
	int mSampleNum;		//�T���v�����L�^���鐔
	int mCount;			//�T���v���񐔉񂵂����ǂ����̃J�E���^
	float mFpsDrawInfo;	//�\���p��FPS
};

