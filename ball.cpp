#include"ball.h"
#include "engine.h"
#include "collision.h"
#include "game.h"

const float PI = 3.1415;

float sign(float a) { return a > 0.f ? 1.f : -1.f; }

void Ball::update()
{
	if (!step(velocity_x * delta_time, 0.f))
	{
		velocity_x = -velocity_x + sign(-velocity_x) * BALL_SPEED_INCREASE;
	}
	if (!step(0.f, velocity_y * delta_time))
	{
		velocity_y = -velocity_y + sign(-velocity_y) * BALL_SPEED_INCREASE;
		switch (hit_direction)
		{
		case right:
			if (velocity_x <= 0)
				velocity_x = -velocity_x + sign(-velocity_x) * BALL_SPEED_INCREASE;

			velocity_x = velocity_x + sign(velocity_x) * BALL_SPEED_INCREASE;
			break;
		case left:
			if (velocity_x >= 0)
				velocity_x = -velocity_x + sign(-velocity_x) * BALL_SPEED_INCREASE;

			velocity_x = velocity_x + sign(velocity_x) * BALL_SPEED_INCREASE;
			break;
		/*case middle://WHAT IF X IS 0 WHEN HIT LEFT/RIGHT!!!!!!!!!!
			velocity_x = 10;*/
			break;
		case other:
			velocity_x = velocity_x;
			break;
		}
	}
}

void Ball::draw()
{
	Circle circle = { x, y , radius };
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	draw_circle(circle);
}

bool Ball::step(float dx, float dy)
{
	Circle circle = { x + dx, y + dy, 4 };
	draw_circle(circle);

	//Collision with borders
	if (x + dx < 0 || x + dx >= 800 || y + dy < 0)
	{
		hit_direction = other;
		return false;
	}
	if (y + dy >= 600)
	{
		alive = false;
		--balls_alive;
		x = 0;
		y = 0;
		velocity_x = 200.f;
		velocity_y = -200.f;
	}

	//Collision with bricks
	for (int i = 0; i < BRICK_MAX; i++)
	{
		Brick& brick = bricks[i];
		if (!brick.alive)
			continue;

		AABB box = AABB::make_from_position_size(brick.x, brick.y, brick.w, brick.h);

		if (aabb_circle_intersect(box, circle))
		{
			brick.count--;
			if (brick.count <= 0)
			{
				brick.alive = false;
				++brick_score;
				if (brick_score >= BALL_5PAWN_AFTER)
				{
					spawn_ball();
				}
			}
			hit_direction = other;
			return false;
		}
	}

	//Collision with player
	AABB player_box = AABB::make_from_position_size(player.x, 500, 50, 15);

	if (dy > 0.f) //fake solution acc to Emil
	{
		if (aabb_circle_intersect(player_box, circle))
		{
			hit_direction = evaluate_direction(player_box, circle);
			return false;
		}
	}

	x += dx;
	y += dy;
	return true;
}

void Ball::spawn_ball()
{
	for ( int i = 0; i < BALL_MAX; i++)
	{
		if (!balls[i].alive)
		{
			balls[i].alive = true;
			++balls_alive;
			brick_score = 0;
			break;
		}
	}
}