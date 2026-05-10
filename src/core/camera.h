/**
* @file camera.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"
#include "../gfx/color.h"

typedef struct {
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
    color_t color;
} camera_t;

camera_t camera_new(color_t color);
