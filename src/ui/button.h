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
    int x;
    int y;
    int w;
    int h;
    bool visible;
    uint16_t pad_button;
    SDL_Texture* texture;
    button_onclick_callback_t onclick;
} button_t;

button_t button(int x, int y);
button_t* button_new(int x, int y);
void button_set_source(button_t* button, const uint8_t* data, size_t size);
void button_set_onclick(button_t* button, button_onclick_callback_t callback);
void button_render(const button_t* button);
