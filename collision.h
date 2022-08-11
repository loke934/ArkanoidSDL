#pragma once
#include "ball.h"

struct Circle
{
	float x;
	float y;
	float radius;
};

void draw_circle(const Circle& circle);
bool circle_intersect(const Circle& a, const Circle& b);

struct AABB
{
	static AABB make_from_position_size(float x, float y, float w, float h);

	float x_min;
	float y_min;
	float x_max;
	float y_max;
};

void draw_box(const AABB& box);
bool aabb_circle_intersect(const AABB& box, const Circle& circle);
float clamp(float t, float min, float max);
float dot(float ax, float bx, float ay, float by);

Direction evaluate_direction(const AABB& box, const Circle& circle);
