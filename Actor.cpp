#include "Actor.h"

//コンストラクタ
CActor::CActor(DblBuffer* obj):
db(obj),
show("■"),
position(0.0f, 1.0f)
{
}

//デストラクタ
CActor::~CActor()
{
	delete(iMgr);
}

//位置更新(引数の位置に設定
void CActor::setActorPosition(Vector2 v)
{
	position = v;
}

//位置更新(引数分移動
void CActor::addActorPosition(Vector2 v)
{
	position = position + v;
}

//更新処理
void CActor::update()
{
	//入力処理更新
	iMgr->UpdateKeyboadState();

	//入力
	position.x = fClamp(position.x += iMgr->GetHorizontal(), (float)DRAW_SIZE_X-1.0f, 0.0f);
	position.y = fClamp(position.y += iMgr->GetVertical(), (float)DRAW_SIZE_Y, 1.0f);
	
	//描画
	draw();
}

//描画処理
void CActor::draw()
{
	db->setCursorPos(floor(position.x), floor(position.y));
	db->setColor(DblBuffer::YELLOW, DblBuffer::BLACK);
	db->write(show);
}

//入力クラスを設定する
void CActor::setInputMgr(InputMgr* mgr)
{
	iMgr = mgr;
}

Vector2 CActor::getPosition()
{
	return position;
}
