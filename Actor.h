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
	Vector2 position;		//アクターの座標
	string show;			//アクターの表示文字
	DblBuffer* db;			//表示用バッファ管理クラス
	InputMgr* iMgr;			//入力用
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

