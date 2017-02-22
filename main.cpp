#include <iostream>
#include <fstream>
#include <math.h>
#include "Player.h"

using namespace std;

int main() {
	DblBuffer db(80, 300);
	FPSMgr2 fps2(30);
	InputMgr iMgr;

	//プレイヤー
	Player player(&db, &fps2, &iMgr);

	//メインループ
	while (true)
	{
		fps2.Update();
		player.update();
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

		db.setCursorPos(DRAW_SIZE_X + 3, 0);
		snprintf(s, 256, "x:%f", player.getPosition().x);
		db.write(s);
		db.setCursorPos(DRAW_SIZE_X + 3, 1);
		snprintf(s, 256, "y:%f", player.getPosition().y);
		db.write(s);

		player.draw();
		db.swap();
		fps2.Wait();
	}
	return 0;
}