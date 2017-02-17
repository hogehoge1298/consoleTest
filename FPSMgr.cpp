#include "FPSMgr.h"

FPSMgr::FPSMgr(int fps)
{
	timeBeginPeriod(1);

	mSampleNum = mFps = fps;

	mIntervalTime = 1000.0 / mFps;	//�w�肳�ꂽFPS�̃t���[���Ԃ̎��Ԃ��擾����

	mFpsDrawInfo = 0.0f;

	mStartTime = mOldTime = timeGetTime();		//���݂̎������L�^����

	mCount = 0;
	
}

FPSMgr::~FPSMgr()
{
	timeEndPeriod(1);    // �^�C�}�[�̐��x��߂�
}

void FPSMgr::Update() {
	double now = timeGetTime();				//���ݎ������擾����
	double def = now - mOldTime;	//�����ɂ����������Ԃ����߂�

	//�J�E���g�����T���v�����ɒB������FPS���v�Z����
	if (mCount == mSampleNum) {
		mFpsDrawInfo = 1000.f / ((now - mStartTime) / (float)mSampleNum);
		mCount = 0;
		mStartTime = now;
	}

	//�������Ԃ��ҋ@���Ԃ��Z����΁A���̎��ԕ��ҋ@����
	if (def < mIntervalTime) {	
		Sleep(mIntervalTime - def);	//�������~�߂�
	}
	mOldTime = now;					//�������X�V����
	mCount++;
}

float FPSMgr::GetFPS()
{
	return mFpsDrawInfo;
}
