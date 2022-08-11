#include "engine.h"

SDL_Window* window;
SDL_Renderer* render;

Key_State keys[SDL_NUM_SCANCODES];
bool get_key(SDL_Scancode key)
{
	return keys[key].state;
}

bool get_key_pressed(SDL_Scancode key)
{
	return keys[key].state && keys[key].change_frame == frame_number;
}

bool get_key_released(SDL_Scancode key)
{
	return !keys[key].state && keys[key].change_frame == frame_number;
}

int frame_number = 0;
float delta_time = 0.f;