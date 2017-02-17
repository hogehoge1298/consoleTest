#pragma once

int Clamp(int val, int max, int min) {
	if (val > max) return max;
	if (val < min) return min;
	return val;
}

float fClamp(float val, float max, float min) {
	if (val > max) return max;
	if (val < min) return min;
	return val;
}