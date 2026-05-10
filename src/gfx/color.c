/**
* @file color.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "color.h"

color_t color_new(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    color_t color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}

SDL_Color color_to_sdl_color(const color_t color) {
    SDL_Color sdl_color;
    sdl_color.r = color.r;
    sdl_color.g = color.g;
    sdl_color.b = color.b;
    sdl_color.a = color.a;
    return sdl_color;
}

color_t color_red(void) {
    return color_new(255, 0, 0, 255);
}

color_t color_green(void) {
    return color_new(0, 255, 0, 255);
}

color_t color_blue(void) {
    return color_new(0, 0, 255, 255);
}

color_t color_white(void) {
    return color_new(255, 255, 255, 255);
}

color_t color_black(void) {
    return color_new(0, 0, 0, 255);
}
