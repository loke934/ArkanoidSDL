#pragma once
#include <SDL/SDL.h>

extern SDL_Window* window;
extern SDL_Renderer* render;

struct Key_State
{
	bool state = false;
	int change_frame = 0;

};
extern Key_State keys[SDL_NUM_SCANCODES];
bool get_key(SDL_Scancode key);
bool get_key_pressed(SDL_Scancode key);
bool get_key_released(SDL_Scancode key);

extern int frame_number;

extern float delta_time;
