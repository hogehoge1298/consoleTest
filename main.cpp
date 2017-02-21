#include "FPSMgr2.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "Actor.h"

using namespace std;

int main() {
	DblBuffer db(80, 300);
	//FPSMgr fps(30);
	FPSMgr2 fps2(30);
	InputMgr iMgr;

	//プレイヤー
	CActor player(&db);
	player.setInputMgr(&iMgr);

	//メインループ
	while (true)
	{
		fps2.Update();
		player.update();
		//iMgr.UpdateKeyboadState();
		db.setCursorPos(0, 0);
		db.setColor(DblBuffer::GREEN, DblBuffer::BLACK);
		char s[256];
		snprintf(s, 256, "%f", fps2.GetFPS());
		db.write(s);
		db.setCursorPos(0, 1);
		db.setColor(DblBuffer::GRAY, DblBuffer::BLACK);
		for (int k = 0; k < DRAW_SIZE_X * DRAW_SIZE_Y; ++k) {
			db.setCursorPos(k % DRAW_SIZE_X, k / DRAW_SIZE_X + 1);
			db.write(" ");     //  背景描画
		}
		//xVal += iMgr.GetHorizontal() ;
		//yVal += iMgr.GetVertical() ;

		//xVal = fClamp(floor(xVal), (float)drawSizeX-1, 0.f);
		db.setCursorPos(DRAW_SIZE_X + 3, 0);
		snprintf(s, 256, "x:%f", player.getPosition().x);
		db.write(s);
		//yVal = fClamp(floor(yVal), (float)drawSizeY, 1.f);
		db.setCursorPos(DRAW_SIZE_X + 3, 1);
		snprintf(s, 256, "y:%f", player.getPosition().y);
		db.write(s);

		//db.setCursorPos(xVal ,yVal);
		//db.setColor(DblBuffer::YELLOW, DblBuffer::BLACK);
		//db.write("■");   //  自機描画

		player.draw();
		db.swap();
		//fps.Update();
		fps2.Wait();
	}
	return 0;
}