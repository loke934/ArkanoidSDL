#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include"engine.h"
#include"player.h"
#include"game.h"
#include <SDL/SDL_ttf.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	TTF_Font* font = TTF_OpenFont("res/roboto.ttf", 14);
	SDL_Surface* text_surf = TTF_RenderText_Solid(font, "Hi hi", {255, 0, 255, 255} );
	SDL_Texture* text_texture =SDL_CreateTextureFromSurface(render, text_surf);

	bool running = true;
	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	set_up_bricks();
	balls[0].alive = true;
	++balls_alive;

	while (running)
	{
		frame_number++;

		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks;
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
			{
				if (event.key.repeat)
					break;

				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
					running = false;

				keys[scancode].state = true;
				keys[scancode].change_frame = frame_number;

				break;
			}

			case SDL_KEYUP:
			{
				int scancode = event.key.keysym.scancode;
				keys[scancode].state = false;
				keys[scancode].change_frame = frame_number;

				break;
			}
			}
		}

		SDL_SetRenderDrawColor(render, 25, 40, 60, 0);
		SDL_RenderClear(render);

		player.update();
		player.draw();

		for (int i = 0; i < BALL_MAX; i++)
		{
			if (!balls[i].alive)
				continue;

			balls[i].update();
			balls[i].draw();
			if (balls_alive <= 0)
			{
				running = false;
			}
		}

		for (int i = 0; i < BRICK_MAX; ++i)
		{
			if (!bricks[i].alive)
				continue;

			bricks[i].draw();
		}

		SDL_Rect text_dst = { 20, 20, text_surf->w, text_surf->h };
		SDL_RenderCopy(render, text_texture, NULL, &text_dst);
		SDL_RenderPresent(render);
	}

	return 0;
}