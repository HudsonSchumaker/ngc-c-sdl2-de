/**
* @file tower.c
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "tower.h"
#include "../gfx/gfx.h"
#include "../core/engine.h"
#include "../ecs/entity_manager.h"
#include "../ecs/texture_component.h"
#include "../ecs/transform_component.h"
#include "t1_png.h"

void tower_create(tower_pool_t* tower_pool, i32 x, i32 y) {
    // Get entity manager
    entity_manager_t* em = engine_get_entity_manager();
    entity_t tower = entity_create_w_tag(em, TAG_TOWER);

    // Initialize transform
    transform_pool_t* transform_pool = engine_get_transform_pool();
    transform_pool->px[tower] = x;
    transform_pool->py[tower] = y;
    transform_pool->sx[tower] = 0.5f;
    transform_pool->sy[tower] = 0.5f;
    transform_pool->ra[tower] = 0.0f;
    transform_pool->zi[tower] = 0;
    
    // Initialize texture
    texture_pool_t* texture_pool = engine_get_texture_pool(); 
    texture_t tower_texture = gfx_load_texture_ex(t1_png, t1_png_size);
    texture_pool->w[tower] = tower_texture.w;
    texture_pool->h[tower] = tower_texture.h;
    texture_pool->texture[tower] = tower_texture.texture;

    // Initialize tower properties
    tower_pool->range[tower] = 32.0f; 
    tower_pool->damage[tower] = 25.0f;  
    tower_pool->cooldown[tower] = 0.0f;
    tower_pool->fire_rate[tower] = 1.0f;
}
