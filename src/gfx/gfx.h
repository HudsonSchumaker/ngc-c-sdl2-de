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
SDL_Texture* gfx_create_text(const uint8_t* data, const size_t size, const char* text, uint8_t text_size, color_t color);

SDL_Rect gfx_get_texture_size(SDL_Texture* texture);
SDL_FRect gfx_get_texture_fsize(SDL_Texture* texture);

void gfx_render_texture(SDL_Texture* texture, int x, int y);

void gfx_draw_line(int x0,int y0, int x1, int y1, color_t color);
void gfx_draw_circle(int cx, int cy, int radius, color_t color);
void gfx_draw_fill_circle(int cx, int cy, int radius, color_t color);
void gfx_draw_dashed_circle(int cx, int cy, int radius, int dash_length, color_t color);

void gfx_draw_box(SDL_Rect rect, color_t color);
void gfx_draw_fbox(SDL_FRect rect, color_t color);

void gfx_draw_fill_box(SDL_Rect rect, color_t color);
void gfx_draw_fill_fbox(SDL_FRect rect, color_t color);

void gfx_draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color);
