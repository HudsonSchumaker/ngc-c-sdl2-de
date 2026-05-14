/**
* @file button.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef void (*button_onclick_callback_t)(void);
typedef struct {
    i32 x;
    i32 y;
    i32 w;
    i32 h;
    bool visible;
    u8 pad_button;
    SDL_Texture* texture;
    button_onclick_callback_t onclick;
} button_t;

button_t button(i32 x, i32 y);
button_t* button_new(i32 x, i32 y);
void button_set_source(button_t* button, const u8* data, size_t size);
void button_set_onclick(button_t* button, button_onclick_callback_t callback);
void button_render(const button_t* button);
