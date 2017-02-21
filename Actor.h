#pragma once
#include <string>
#include <math.h>
#include "Vector2.h"
#include "define.h"
#include "DblBuffer.h"
#include "InputMgr.h"
using namespace std;

class CActor
{
private:
	Vector2 position;		//�A�N�^�[�̍��W
	string show;			//�A�N�^�[�̕\������
	DblBuffer* db;			//�\���p�o�b�t�@�Ǘ��N���X
	InputMgr* iMgr;			//���͗p
public:
	CActor(DblBuffer*);
	~CActor();

	void setActorPosition(Vector2 v);
	void addActorPosition(Vector2 v);
	void update();
	void draw();

	void setInputMgr(InputMgr*);

	Vector2 getPosition();
};

