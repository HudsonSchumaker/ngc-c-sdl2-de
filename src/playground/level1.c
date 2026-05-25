/**
 * @file level1.c
 * @author Hudson Schumaker
 * @version 1.0.0
 *
 * Dodoi-Engine is a game engine developed by Dodoi-Lab.
 * @copyright Copyright (c) 2024, Dodoi-Lab
 */
#include "enemy.h"
#include "tower.h"
#include "level1.h"
#include "../de-ngc/gfx/gfx.h"
#include "../de-ngc/util/map.h"
#include "../de-ngc/core/engine.h"
#include "../de-ngc/core/camera.h"
#include "../de-ngc/ecs/radar_system.h"
#include "../de-ngc/ecs/render_system.h"
#include "grass_png.h"
#include "path_png.h"

static bool running = false;
static map_t map;
static camera_t camera;
static tower_pool_t tower_pool;
static enemy_pool_t enemy_pool;
static scene_t* level1 = NULL;

static const char *level1_data[MAP_HEIGHT][MAP_WIDTH] = {
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"},
    {"g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0", "g0"}};

void level1_init(void) {
    level1 = (scene_t *)malloc(sizeof(scene_t));
    if (level1 == NULL) {
        exit(EXIT_FAILURE);
    }

    level1->load = level1_load;
    level1->input = level1_input;
    level1->update = level1_update;
    level1->render = level1_render;
    level1->run = level1_run;
    level1->unload = level1_unload;
}

void level1_load(void) {
    map_load(&map, level1_data);
    map.textures[0] = gfx_load_texture(grass_png, grass_png_size);
    map.textures[1] = gfx_load_texture(path_png, path_png_size);
    camera = camera_new(color_white());

    tower_create(&tower_pool, 5 * 32.0f, 6 * 32.0f);
    enemy_create(&enemy_pool, 0.0f, 7 * 32.0f);
    enemy_create(&enemy_pool, -32.0f, 7 * 32.0f);
    enemy_create(&enemy_pool, -64.0f, 7 * 32.0f);
    enemy_create(&enemy_pool, -96.0f, 7 * 32.0f);
    enemy_create(&enemy_pool, -128.0f, 7 * 32.0f);

    running = true;
}

void level1_input(void) {}

void level1_update(void) {
    f32 delta_time = engine_calculate_delta_time();
    enemy_move(&enemy_pool, delta_time);
    radar_system(TAG_TOWER, TAG_ENEMY);
}

void level1_render(void) {
    scene_begin_render();
    {
        map_render(&map);
        render_system(engine_get_transform_pool(), engine_get_texture_pool(), &camera);
    }
    scene_end_render();
}

u8 level1_run(void) {
    while (running) {
        level1_input();
        level1_update();
        level1_render();
    }
    return 0;
}

void level1_unload(void) {
    for (short i = 0; i < 8; ++i) {
        if (map.textures[i]){
            SDL_DestroyTexture(map.textures[i]);
        }
    }
    free(level1);
    level1 = NULL;
}

scene_t *level1_get_scene(void) {
    return level1;
}
