#pragma once

//�萔��`
const int DRAW_SIZE_X = 45;
const int DRAW_SIZE_Y = 25;


//�֐���`
static int Clamp(int val, int max, int min) {
	if (val > max) return max;
	if (val < min) return min;
	return val;
}

static float fClamp(float val, float max, float min) {
	if (val > max) return max;
	if (val < min) return min;
	return val;
}