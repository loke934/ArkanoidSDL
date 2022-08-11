#include"collision.h"
#include"engine.h"
#include <SDL/SDL.h>

const float PI = 3.1415;

void draw_circle(const Circle& circle)
{
	int resoulution = 48;
	float step = (2 * PI) / resoulution;

	for (int i = 0; i < resoulution; ++i)
	{
		float angle = step * i;
		float x1 = cos(angle);
		float y1 = sin(angle);

		float next_angle = step * (i + 1);
		float x2 = cos(next_angle);
		float y2 = sin(next_angle);

		SDL_RenderDrawLine(render,
			x1 * circle.radius + circle.x,
			y1 * circle.radius + circle.y,
			x2 * circle.radius + circle.x,
			y2 * circle.radius + circle.y
		);
	}
}

AABB AABB::make_from_position_size(float x, float y, float w, float h)
{
	AABB box;
	box.x_min = x - w / 2;
	box.y_min = y - h / 2;
	box.x_max = x + w / 2;
	box.y_max = y + h / 2;

	return box;
}

void draw_box(const AABB& box)
{
	SDL_Rect rect = {
		(int)box.x_min,
		(int)box.y_min,
		(int)box.x_max - (int)box.x_min,
		(int)box.y_max - (int)box.y_min
	};

	SDL_RenderFillRect(render, &rect);
}

bool aabb_circle_intersect(const AABB& box, const Circle& circle)
{
	float closest_point_x = clamp(box.x_min, box.x_max, circle.x);
	float closest_point_y = clamp(box.y_min, box.y_max, circle.y);

	float difference_x = closest_point_x - circle.x;
	float difference_y = closest_point_y - circle.y;

	float distanceSq = dot(difference_x, difference_x, difference_y, difference_y);
	float distance = sqrt(distanceSq);

	if (distance < circle.radius)
		return true;

	return false;
}

Direction evaluate_direction(const AABB& box, const Circle& circle)
{
	float middle_point_x = (box.x_min + box.x_max) * 0.5f;
	/*float middle_min = middle_point_x - 5;
	float middle_max = middle_point_x + 5;

	if (circle.x < middle_max && circle.x > middle_min)
		return middle;*/

	if (circle.x >= middle_point_x)
		return right;

	if (circle.x < middle_point_x)
		return left;
}

float dot(float ax, float bx, float ay, float by)
{
	return (ax * bx) + (ay * by);
}

float clamp(float min, float max, float t)
{
	if (t < min)
		return min;
	if (t > max)
		return max;

	return t;
}
