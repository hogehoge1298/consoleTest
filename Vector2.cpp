#include "Vector2.h"

Vector2::Vector2() :
	x(0),
	y(0)
{
}

Vector2::Vector2(float initX, float initY) :
	x(initX),
	y(initY)
{
}

Vector2 Vector2::operator+(Vector2 v)
{
	v.x = x + v.x;
	v.y = y + v.y;
	return v;
}

Vector2 Vector2::operator-(Vector2 v)
{
	v.x = x - v.x;
	v.y = y - v.y;
	return v;
}
