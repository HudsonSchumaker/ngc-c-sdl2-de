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
    int x;
    int y;
    int w;
    int h;
    bool visible;
    color_t color;
    uint8_t font_size;
    SDL_Texture* texture;
} label_t;

label_t label(int x, int y, const char* text);
label_t* label_new(int x, int y, const char* text);

void label_set_color(label_t* label, color_t color);
void label_set_font_size(label_t* label, uint8_t font_size, const uint8_t* data, size_t size);
void label_render(const label_t* label);
void label_set_on_center(label_t* label);
void label_set_horizontal_center(label_t* label);
