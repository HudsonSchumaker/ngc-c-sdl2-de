/**
 * @file level1.c
 * @author Hudson Schumaker
 * @version 1.0.0
 *
 * Dodoi-Engine is a game engine developed by Dodoi-Lab.
 * @copyright Copyright (c) 2024, Dodoi-Lab
 */
#include "enemy.h"
#include "level1.h"
#include "../gfx/gfx.h"
#include "../util/map.h"
#include "../core/engine.h"
#include "../core/camera.h"
#include "../ecs/render_system.h"
#include "grass_png.h"
#include "path_png.h"
#include "orc_png.h"
#include "t1_png.h"

static bool running = false;
static scene_t* level1 = NULL;
static entity_manager_t* em = NULL;
static map_t map;

static enemy_t enemie;
static SDL_Texture *enemy_texture = NULL;

static camera_t camera;
static entity_t tower;
static transform_pool_t transform_pool;
static texture_pool_t texture_pool;

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
    enemy_texture = gfx_load_texture(orc_png, orc_png_size);
    enemie = enemy(0, 7 * MAP_TILE_SIZE, MAP_TILE_SIZE, MAP_TILE_SIZE, 100, 25.0f);
    enemie.texture = enemy_texture;

    em = engine_get_entity_manager();
    tower = entity_create(em);
    texture_t tower_texture = gfx_load_texture_ex(t1_png, t1_png_size);
    texture_pool.w[tower] = tower_texture.w;
    texture_pool.h[tower] = tower_texture.h;
    texture_pool.texture[tower] = tower_texture.texture;

    transform_pool.px[tower] = 5 * MAP_TILE_SIZE;
    transform_pool.py[tower] = 6 * MAP_TILE_SIZE;
    transform_pool.sx[tower] = 0.5f;
    transform_pool.sy[tower] = 0.5f;
    transform_pool.ra[tower] = 0.0f;

    running = true;
}

void level1_input(void) {}

void level1_update(void) {
    float delta_time = engine_calculate_delta_time();
    enemy_update(&enemie, delta_time);
}

void level1_render(void) {
    scene_begin_render();
    {
        map_render(&map);
        enemy_render(&enemie);
        render_system(&transform_pool, &texture_pool, &camera);
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

    if (enemy_texture) {
        SDL_DestroyTexture(enemy_texture);
    }
}

scene_t *level1_get_scene(void) {
    return level1;
}
