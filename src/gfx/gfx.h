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

SDL_Texture* gfx_load_texture(const u8* data, const size_t size);
SDL_Texture* gfx_create_text(const u8* data, const size_t size, const char* text, u8 text_size, color_t color);

SDL_Rect gfx_get_texture_size(SDL_Texture* texture);
SDL_FRect gfx_get_texture_fsize(SDL_Texture* texture);

void gfx_render_texture(SDL_Texture* texture, i32 x, i32 y, i32 w, i32 h);
void gfx_render_texture_rotated(SDL_Texture* texture, i32 x, i32 y, i32 w, i32 h, double angle);

void gfx_draw_line(i32 x0, i32 y0, i32 x1, i32 y1, color_t color);
void gfx_draw_circle(i32 cx, i32 cy, i32 radius, color_t color);
void gfx_draw_fill_circle(i32 cx, i32 cy, i32 radius, color_t color);
void gfx_draw_dashed_circle(i32 cx, i32 cy, i32 radius, i32 dash_length, color_t color);

void gfx_draw_box(SDL_Rect rect, color_t color);
void gfx_draw_fbox(SDL_FRect rect, color_t color);

void gfx_draw_fill_box(SDL_Rect rect, color_t color);
void gfx_draw_fill_fbox(SDL_FRect rect, color_t color);

void gfx_draw_triangle(i32 x1, i32 y1, i32 x2, i32 y2, i32 x3, i32 y3, color_t color);
