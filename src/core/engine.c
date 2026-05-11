/**
* @file engine.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "engine.h"
#include "context.h"
#include "../math/de_math.h"
#include "../playground/splash_screen.h"

static float delta_time = 0.0f;

void engine_init(void) {
    if (ctx_init() != 0) {
        exit(EXIT_FAILURE);
    }

    build_trigo_tables();

    splash_screen_init();
    splash_screen_get_scene()->load();
    splash_screen_get_scene()->run();
}

void engine_quit(void) {
    ctx_quit();
}

float engine_calculate_delta_time(void) {
    static uint32_t last_time = 0;
    uint32_t current_time = SDL_GetTicks();
    delta_time = (current_time - last_time) / 1000.0f; // Convert to seconds
    last_time = current_time;
    return delta_time;
}

float engine_get_delta_time(void) {
    return delta_time;
}
