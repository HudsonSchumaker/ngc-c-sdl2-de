/**
 * @file game.c
 * @author Hudson Schumaker
 * @version 1.0.0
 *
 * Dodoi-Engine is a game engine developed by Dodoi-Lab.
 * @copyright Copyright (c) 2024, Dodoi-Lab
 */
#include "game.h"
#include "level1.h"
#include "splash_screen.h"
#include "../de-ngc/core/engine.h"

void game_start(void) {
    engine_init();

    splash_screen_init();
    splash_screen_get_scene()->load();
    splash_screen_get_scene()->run();
    splash_screen_get_scene()->unload();

    level1_init();
    level1_get_scene()->load();
    level1_get_scene()->run();
    level1_get_scene()->unload();

    engine_quit();
}
