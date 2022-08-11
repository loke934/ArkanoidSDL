#pragma once

enum Direction
{
	right,
	left,
	middle,
	other
};

struct Ball
{
	float x;
	float y;
	float radius;

	float velocity_x = 200.f;
	float velocity_y = -200.f;

	bool alive = false;

	Direction hit_direction;

	void update();
	void draw();

	bool step(float dx, float dy);

	void spawn_ball();
};