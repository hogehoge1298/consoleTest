#include "Actor.h"

CActor::CActor()
{
}

//デストラクタ
CActor::~CActor()
{
	if(iMgr)
		delete iMgr;
	if(fpsMgr)
		delete fpsMgr;
	if(db)
		delete db;
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
	//入力用クラスが設定されてるとき
	/*if (iMgr) {
		//入力処理更新
		iMgr->UpdateKeyboadState();

		//入力
		position.x = fClamp(position.x += iMgr->GetHorizontal() * fpsMgr->GetDeltaTime(), (float)DRAW_SIZE_X - 1.0f, 0.0f);
		position.y = fClamp(position.y += iMgr->GetVertical() * fpsMgr->GetDeltaTime(), (float)DRAW_SIZE_Y, 1.0f);
	}*/

	//移動
	move();
	//描画
	draw();
}

void CActor::draw()
{
}

void CActor::move()
{
}

//描画処理
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

//入力クラスを設定する
void CActor::setInputMgr(InputMgr* obj)
{
	iMgr = obj;
}