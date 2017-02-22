#include "Actor.h"

CActor::CActor()
{
}

//�f�X�g���N�^
CActor::~CActor()
{
	if(iMgr)
		delete iMgr;
	if(fpsMgr)
		delete fpsMgr;
	if(db)
		delete db;
}

//�ʒu�X�V(�����̈ʒu�ɐݒ�
void CActor::setActorPosition(Vector2 v)
{
	position = v;
}

//�ʒu�X�V(�������ړ�
void CActor::addActorPosition(Vector2 v)
{
	position = position + v;
}

//�X�V����
void CActor::update()
{
	//���͗p�N���X���ݒ肳��Ă�Ƃ�
	/*if (iMgr) {
		//���͏����X�V
		iMgr->UpdateKeyboadState();

		//����
		position.x = fClamp(position.x += iMgr->GetHorizontal() * fpsMgr->GetDeltaTime(), (float)DRAW_SIZE_X - 1.0f, 0.0f);
		position.y = fClamp(position.y += iMgr->GetVertical() * fpsMgr->GetDeltaTime(), (float)DRAW_SIZE_Y, 1.0f);
	}*/

	//�ړ�
	move();
	//�`��
	draw();
}

void CActor::draw()
{
}

void CActor::move()
{
}

//�`�揈��
/*void CActor::draw()
{
	db->setCursorPos(floor(position.x), floor(position.y));
	db->setColor(DblBuffer::YELLOW, DblBuffer::BLACK);
	db->write(show);
}*/

Vector2 CActor::getPosition()
{
	return position;
}

void CActor::setString(string s)
{
	show = s;
}

void CActor::setDblBuffer(DblBuffer *obj)
{
	db = obj;
}

void CActor::setFpsMgr(FPSMgr2 *obj)
{
	fpsMgr = obj;
}

//���̓N���X��ݒ肷��
void CActor::setInputMgr(InputMgr* obj)
{
	iMgr = obj;
}