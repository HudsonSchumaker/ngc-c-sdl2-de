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
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} color_t;

color_t color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
color_t* color_new(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
SDL_Color color_to_sdl_color(const color_t color);

color_t color_red(void);
color_t color_green(void);
color_t color_blue(void);
color_t color_white(void);
color_t color_black(void);
color_t color_silver(void);
color_t color_gray(void);
color_t color_yellow(void);
