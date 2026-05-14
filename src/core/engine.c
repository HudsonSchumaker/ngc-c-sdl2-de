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
#include "../playground/level1.h"

static float delta_time = 0.0f;

void engine_init(void) {
    if (ctx_init() != 0) {
        exit(EXIT_FAILURE);
    }

    build_trigo_tables();

    splash_screen_init();
    splash_screen_get_scene()->load();
    splash_screen_get_scene()->run();
    splash_screen_get_scene()->unload();

    level1_init();
    level1_get_scene()->load();
    level1_get_scene()->run();
    level1_get_scene()->unload();
}

void engine_quit(void) {
    ctx_quit();
}

float engine_calculate_delta_time(void) {
    static u64 frequency = 0;
    static u64 last_counter = 0;
    static float smooth_dt = 0.0f;

    const float MAX_DT = 0.25f;
    const float SMOOTH_ALPHA = 0.08f;

    if (frequency == 0) {
        frequency = SDL_GetPerformanceFrequency();
    }
    u64 now = SDL_GetPerformanceCounter();

    if (last_counter == 0) {
        last_counter = now;
        return 0.0f;
    }

    float dt = (float)(now - last_counter) / (float)frequency;
    last_counter = now;

    if (dt < 0.0f) {
        dt = 0.0f;
    }

    if (dt > MAX_DT) {
        dt = MAX_DT;
    }

    if (smooth_dt == 0.0f) {
        smooth_dt = dt;
    } else {
        smooth_dt += SMOOTH_ALPHA * (dt - smooth_dt);
    }

    delta_time = smooth_dt;
    return delta_time;
}

float engine_get_delta_time(void) {
    return delta_time;
}
