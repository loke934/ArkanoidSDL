#pragma once

struct Player
{
	float x = 100.f;
	float y = 0.f;
	float speed = 800.f;

	float shoot_timer = 0.f;
	int next_projectile_index = 0;

	void update();
	void draw();
};
