#include "FPSMgr.h"
#include "FPSMgr2.h"
#include "InputMgr.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "DblBuffer.h"
#include "define.h"

using namespace std;

int drawSizeX = 40;
int drawSizeY = 20;

int main() {
	DblBuffer db(80, 300);
	//FPSMgr fps(30);
	FPSMgr2 fps2(30);
	InputMgr iMgr;

	float xVal = 0.0f;
	float yVal = 1.0f;

	while (true)
	{
		fps2.Update();
		iMgr.UpdateKeyboadState();
		db.setCursorPos(0, 0);
		db.setColor(DblBuffer::GREEN, DblBuffer::BLACK);
		char s[256];
		snprintf(s, 256, "%f", fps2.GetFPS());
		db.write(s);
		db.setCursorPos(0, 1);
		db.setColor(DblBuffer::GRAY, DblBuffer::BLACK);
		for (int k = 0; k < drawSizeX * drawSizeY; ++k) {
			db.setCursorPos(k % drawSizeX, k / drawSizeX + 1);
			db.write(" ");     //  ”wŒi•`‰æ
		}
		xVal += iMgr.GetHorizontal() ;
		yVal += iMgr.GetVertical() ;

		xVal = fClamp(floor(xVal), (float)drawSizeX-1, 0.f);
		db.setCursorPos(drawSizeX + 3, 0);
		snprintf(s, 256, "x:%f", xVal);
		db.write(s);
		yVal = fClamp(floor(yVal), (float)drawSizeY, 1.f);
		db.setCursorPos(drawSizeX, 1);
		snprintf(s, 256, "y:%f", yVal);
		db.write(s);

		db.setCursorPos(xVal ,yVal);
		db.setColor(DblBuffer::YELLOW, DblBuffer::BLACK);
		db.write("¡");   //  Ž©‹@•`‰æ
		db.swap();
		//fps.Update();
		fps2.Wait();
	}
	return 0;
}