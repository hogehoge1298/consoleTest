#pragma once
#include <string>
#include <math.h>
#include "Vector2.h"
#include "define.h"
#include "DblBuffer.h"
#include "InputMgr.h"
#include "FPSMgr2.h"
using namespace std;

class CActor
{
protected:
	Vector2 position;		//�A�N�^�[�̍��W
	string show;			//�A�N�^�[�̕\������
	DblBuffer* db;			//�\���p�o�b�t�@�Ǘ��N���X
	InputMgr* iMgr;			//���͗p
	FPSMgr2* fpsMgr;		//FPS�Ǘ��N���X

public:
	CActor();
	~CActor();

	void setActorPosition(Vector2 v);
	void addActorPosition(Vector2 v);
	void update();
	virtual void draw();

	virtual void move();

	Vector2 getPosition();

	void setString(string c);

	void setDblBuffer(DblBuffer*);
	void setFpsMgr(FPSMgr2*);
	void setInputMgr(InputMgr*);
};

