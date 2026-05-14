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
    i16 x;
    i16 y;
    i16 w;
    i16 h;
    color_t color;
} camera_t;

camera_t camera_new(color_t color);
