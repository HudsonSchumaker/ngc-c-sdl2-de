/**
* @file render_system.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "render_system.h"
#include "entity_manager.h"
#include "../core/engine.h"
#include "../core/context.h"

void render_system(transform_pool_t* t, texture_pool_t* r) {
    SDL_Renderer* renderer = ctx_get_renderer();
    entity_manager_t* em = engine_get_entity_manager();
    
    for (entity_t i = 0; i < MAX_ENTITIES; i++) {
        if (em->alive[i] && r->texture[i]) {
            SDL_FRect dest = { t->px[i], t->py[i], r->w[i] * t->sx[i], r->h[i] * t->sy[i] };
            SDL_RenderCopyF(renderer, r->texture[i], NULL, &dest);
        }
    }
}
