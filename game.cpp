#include"game.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>

Player player;
Ball ball = { 100, 80, 6 };
Brick bricks[BRICK_MAX];

Ball balls[BALL_MAX];
int brick_score = 0;
int balls_alive = 0;

void set_up_bricks()
{
	srand(time(nullptr));
	for (int i = 0; i < BRICK_MAX; i++)
	{
		bricks[i].x = (i % 13) * 52 + 90;
		bricks[i].y = (i % 9) * 27 + 120;
		bricks[i].count = rand() % 3 + 1;
		switch (bricks[i].count)
		{
		case 1:
			bricks[i].brick_color = Color::One;
			break;
		case 2:
			bricks[i].brick_color = Color::Two;
			break;
		case 3:
			bricks[i].brick_color = Color::Three;
			break;
		}

	}
}