#include "Player.h"

Player::Player()
{
}

Player::Player(DblBuffer *dblObj, FPSMgr2 *fpsObj, InputMgr *inputObj)
{
	setDblBuffer(dblObj);
	setFpsMgr(fpsObj);
	setInputMgr(inputObj);

	//�����Z�b�g
	setString("��");

	//�������W
	setActorPosition(Vector2(0.0f, 1.0f));
}


Player::~Player()
{
	CActor::~CActor();
}


void Player::move()
{
	if (iMgr) {
		//���͏����X�V
		iMgr->UpdateKeyboadState();

		//����
		position.x = fClamp(position.x += iMgr->GetHorizontal() * fpsMgr->GetDeltaTime(), (float)DRAW_SIZE_X - 1.0f, 0.0f);
		position.y = fClamp(position.y += iMgr->GetVertical() * fpsMgr->GetDeltaTime(), (float)DRAW_SIZE_Y, 1.0f);
	}
}

void Player::draw()
{
	db->setCursorPos(floor(position.x), floor(position.y));
	db->setColor(DblBuffer::YELLOW, DblBuffer::BLACK);
	db->write(show);
}