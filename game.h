#pragma once
#include"player.h"
#include"ball.h"
#include "brick.h"

#define PROJECTILE_MAX 20
#define BRICK_MAX 117
#define BALL_MAX 5
#define BALL_5PAWN_AFTER 5
#define BALL_SPEED_INCREASE 2

extern Player player;
extern Brick bricks[BRICK_MAX];
extern Ball ball;

extern Ball balls[BALL_MAX];
extern int brick_score;
extern int balls_alive;

void set_up_bricks();