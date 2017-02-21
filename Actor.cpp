#include "Actor.h"

//�R���X�g���N�^
CActor::CActor(DblBuffer* obj):
db(obj),
show("��"),
position(0.0f, 1.0f)
{
}

//�f�X�g���N�^
CActor::~CActor()
{
	delete(iMgr);
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
	//���͏����X�V
	iMgr->UpdateKeyboadState();

	//����
	position.x = fClamp(position.x += iMgr->GetHorizontal(), (float)DRAW_SIZE_X-1.0f, 0.0f);
	position.y = fClamp(position.y += iMgr->GetVertical(), (float)DRAW_SIZE_Y, 1.0f);
	
	//�`��
	draw();
}

//�`�揈��
void CActor::draw()
{
	db->setCursorPos(floor(position.x), floor(position.y));
	db->setColor(DblBuffer::YELLOW, DblBuffer::BLACK);
	db->write(show);
}

//���̓N���X��ݒ肷��
void CActor::setInputMgr(InputMgr* mgr)
{
	iMgr = mgr;
}

Vector2 CActor::getPosition()
{
	return position;
}
