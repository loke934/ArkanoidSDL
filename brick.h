#pragma once

enum class Color {
	One,
	Two,
	Three
};

class Brick
{
public:
	bool alive = true;
	Color brick_color;
	int count;

	float x = 0;
	float y = 0;

	float w = 50.f;
	float h = 25.f;

	void draw();
};
