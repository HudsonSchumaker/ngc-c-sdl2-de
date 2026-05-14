/**
* @file color.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} color_t;

color_t color(u8 r, u8 g, u8 b, u8 a);
color_t* color_new(u8 r, u8 g, u8 b, u8 a);
SDL_Color color_to_sdl_color(const color_t color);

color_t color_red(void);
color_t color_green(void);
color_t color_blue(void);
color_t color_white(void);
color_t color_black(void);
color_t color_silver(void);
color_t color_gray(void);
color_t color_yellow(void);
