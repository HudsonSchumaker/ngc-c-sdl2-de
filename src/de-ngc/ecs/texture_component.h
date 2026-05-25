/**
* @file texture_render.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../de.h"

/**
 * @brief A texture pool that holds the textures and their dimensions for all entities.
 */
typedef struct {
    i32 w[MAX_ENTITIES];
    i32 h[MAX_ENTITIES];
    SDL_Texture* texture[MAX_ENTITIES];
} texture_pool_t;
