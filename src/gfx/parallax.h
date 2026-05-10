/**
* @file parallax.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef struct {
	SDL_Texture* background;
	SDL_Texture* texture;
	SDL_Rect bg_rect;
	SDL_Rect rect_a;
	SDL_Rect rect_b;
	SDL_Point size;
} parallax_vertical_t;

typedef struct {
	SDL_Texture* background;
	SDL_Texture* texture;
	SDL_Rect bg_rect;
	SDL_Rect rect_a;
	SDL_Rect rect_b;
	SDL_Point size;
} parallax_horizontal_t;

parallax_vertical_t parallax_vertical_simple(const uint8_t* parallax_data, const size_t parallax_size);
parallax_vertical_t parallax_vertical_double(const uint8_t* bg_data, const size_t bg_size, const uint8_t* parallax_data, const size_t parallax_size);
parallax_vertical_t* parallax_vertical_simple_new(const uint8_t* parallax_data, const size_t parallax_size);
parallax_vertical_t* parallax_vertical_double_new(const uint8_t* bg_data, const size_t bg_size, const uint8_t* parallax_data, const size_t parallax_size);
void parallax_vertical_update(parallax_vertical_t* parallax);
void parallax_vertical_render(const parallax_vertical_t* parallax);

parallax_horizontal_t parallax_horizontal_simple(const uint8_t* parallax_data, const size_t parallax_size);
parallax_horizontal_t parallax_horizontal_double(const uint8_t* bg_data, const size_t bg_size, const uint8_t* parallax_data, const size_t parallax_size);
parallax_horizontal_t* parallax_horizontal_simple_new(const uint8_t* parallax_data, const size_t parallax_size);
parallax_horizontal_t* parallax_horizontal_double_new(const uint8_t* bg_data, const size_t bg_size, const uint8_t* parallax_data, const size_t parallax_size);
void parallax_horizontal_update(parallax_horizontal_t* parallax);
void parallax_horizontal_render(const parallax_horizontal_t* parallax);
