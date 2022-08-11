#include "brick.h"
#include "collision.h"
#include "engine.h"
#include <SDL/SDL.h>


void Brick::draw()
{
	AABB box = AABB::make_from_position_size(x, y, w, h);
	switch (brick_color)
	{
	case Color::One:
		SDL_SetRenderDrawColor(render, 39, 170, 137, 255);
		break;
	case Color::Two:
		SDL_SetRenderDrawColor(render, 20, 100, 180, 255);
		break;
	case Color::Three:
		SDL_SetRenderDrawColor(render, 255, 192, 203, 255);
		break;
	default:
		SDL_SetRenderDrawColor(render, 255, 190, 200, 255);
		break;
	}
	draw_box(box);
}
