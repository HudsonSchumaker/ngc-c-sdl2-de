/**
* @file label.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"
#include "../gfx/color.h"

typedef struct {
    char* text;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
    int16_t font_size;
    SDL_Texture* texture;
    color_t color;
    bool visible;
} label_t;

label_t label_new(int32_t x, int32_t y, const char* text);

void label_set_color(label_t* label, color_t color);
void label_set_font_size(label_t* label, int16_t font_size, const uint8_t* data, size_t size);
void label_render(const label_t* label);
void label_set_on_center(label_t* label);
void label_set_horizontal_center(label_t* label);
