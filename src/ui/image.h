/**
* @file image.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"
#include "../gfx/color.h"

typedef struct {
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
    SDL_Texture* texture;
    color_t color;
    bool visible;
} image_t;

image_t image_new(int32_t x, int32_t y);
void image_set_source(image_t* image, const uint8_t* data, size_t size);
void image_set_tint(image_t* image, color_t color);
void image_render(const image_t* image);
