/**
* @file engine.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "engine.h"
#include "context.h"
#include "../math/math2d.h"
#include "../playground/splash_screen.h"
#include "../playground/level1.h"

static f32 delta_time = 0.0f;

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

f32 engine_calculate_delta_time(void) {
    static u64 frequency = 0;
    static u64 last_counter = 0;
    static f32 smooth_dt = 0.0f;

    const f32 MAX_DT = 0.25f;
    const f32 SMOOTH_ALPHA = 0.08f;

    if (frequency == 0) {
        frequency = SDL_GetPerformanceFrequency();
    }
    u64 now = SDL_GetPerformanceCounter();

    if (last_counter == 0) {
        last_counter = now;
        return 0.0f;
    }

    f32 dt = (f32)(now - last_counter) / (f32)frequency;
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

f32 engine_get_delta_time(void) {
    return delta_time;
}
