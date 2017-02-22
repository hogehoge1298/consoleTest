#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(float, float);

	Vector2 operator+(Vector2);
	Vector2 operator-(Vector2);

	float x;
	float y;
};

