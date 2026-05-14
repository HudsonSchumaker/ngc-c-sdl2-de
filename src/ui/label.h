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
    i32 x;
    i32 y;
    i32 w;
    i32 h;
    bool visible;
    color_t color;
    u8 font_size;
    SDL_Texture* texture;
} label_t;

label_t label(i32 x, i32 y, const char* text);
label_t* label_new(i32 x, i32 y, const char* text);

void label_set_color(label_t* label, color_t color);
void label_set_font_size(label_t* label, u8 font_size, const u8* data, size_t size);
void label_render(const label_t* label);
void label_set_on_center(label_t* label);
void label_set_horizontal_center(label_t* label);
