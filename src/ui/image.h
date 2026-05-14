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
    i32 x;
    i32 y;
    i32 w;
    i32 h;
    bool visible;
    color_t color;
    SDL_Texture* texture;
} image_t;

image_t image(i32 x, i32 y);
image_t* image_new(i32 x, i32 y);
void image_set_source(image_t* image, const u8* data, size_t size);
void image_set_tint(image_t* image, color_t color);
void image_render(const image_t* image);
