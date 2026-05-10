/**
* @file gfx.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "color.h"
#include "../pch.h"

SDL_Texture* gfx_load_texture(const uint8_t* data, const size_t size);
SDL_Texture* gfx_create_text(const uint8_t* data, const size_t size, const char* text, uint8_t text_size, const color_t color);

SDL_Rect gfx_get_texture_size(SDL_Texture* texture);
SDL_FRect gfx_get_texture_fsize(SDL_Texture* texture);

void gfx_draw_line(const int x0, const int y0, const int x1, const int y1, const color_t color);
void gfx_draw_circle(const int cx, const int cy, const int radius, const color_t color);
void gfx_draw_fill_circle(const int cx, const int cy, const int radius, const color_t color);
void gfx_draw_dashed_circle(const int cx, const int cy, const int radius, const int dash_length, const color_t color);

void gfx_draw_box(const SDL_Rect rect, const color_t color);
void gfx_draw_fbox(const SDL_FRect rect, const color_t color);

void gfx_draw_fill_box(const SDL_Rect rect, const color_t color);
void gfx_draw_fill_fbox(const SDL_FRect rect, const color_t color);

void gfx_draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const color_t color);
