/**
 * @file enemy.c
 * @author Hudson Schumaker
 * @version 1.0.0
 *
 * Dodoi-Engine is a game engine developed by Dodoi-Lab.
 * @copyright Copyright (c) 2024, Dodoi-Lab
 */
#include "enemy.h"
#include "../de-ngc/gfx/gfx.h"
#include "../de-ngc/core/engine.h"
#include "../de-ngc/ecs/entity_manager.h"
#include "../de-ngc/ecs/texture_component.h"
#include "../de-ngc/ecs/transform_component.h"
#include "orc_png.h"

void enemy_create(enemy_pool_t* enemy_pool, i32 x, i32 y) {
    // Get entity manager
    entity_manager_t* em = engine_get_entity_manager();
    entity_t enemy = entity_create_w_tag(em, TAG_ENEMY);

    // Initialize transform
    transform_pool_t* transform_pool = engine_get_transform_pool();
    transform_pool->px[enemy] = x;
    transform_pool->py[enemy] = y;
    transform_pool->sx[enemy] = 0.5f;
    transform_pool->sy[enemy] = 0.5f;
    transform_pool->ra[enemy] = 0.0f;
    transform_pool->zi[enemy] = 1;

    // Initialize texture
    texture_pool_t* texture_pool = engine_get_texture_pool();
    texture_t enemy_texture = gfx_load_texture_ex(orc_png, orc_png_size);
    texture_pool->w[enemy] = enemy_texture.w;
    texture_pool->h[enemy] = enemy_texture.h;
    texture_pool->texture[enemy] = enemy_texture.texture;

    // Initialize enemy properties
    enemy_pool->speed[enemy] = 25.0f;
    enemy_pool->health[enemy] = 100.0f;
}

void enemy_move(enemy_pool_t* enemy_pool, f32 delta_time) {
    entity_manager_t* em = engine_get_entity_manager();
    transform_pool_t* transform_pool = engine_get_transform_pool();

    for (entity_t i = 0; i < MAX_ENTITIES; i++) {
        if (em->alive[i] && em->tag[i] == TAG_ENEMY) {
            transform_pool->px[i] += enemy_pool->speed[i] * delta_time;
        }
    }
}
