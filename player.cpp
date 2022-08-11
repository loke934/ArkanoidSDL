#include"player.h"
#include "engine.h"
#include "game.h"
#include "collision.h"


void Player::update()
{
	//movement
	if (get_key(SDL_SCANCODE_D))
	{
		if (!(x + (x * delta_time) >= (800 - 25))) //CHECK THIS!!
			x += speed * delta_time;
	}

	if (get_key(SDL_SCANCODE_A))
	{
		if (!(x + (x * delta_time) < 25))
			x -= speed * delta_time;
	}
}

void Player::draw()
{
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	AABB box = AABB::make_from_position_size((int)x, 500, 50, 15);
	draw_box(box);
}


