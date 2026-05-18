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

void render_system(transform_pool_t* t, texture_pool_t* r, camera_t* c) {
    SDL_Renderer* renderer = ctx_get_renderer();
    entity_manager_t* em = engine_get_entity_manager();
    
    for (entity_t i = 0; i < MAX_ENTITIES; i++) {
        if (em->alive[i] && r->texture[i]) {
            float x = t->px[i];
            float y = t->py[i];
            float angle = t->ra[i];
            float w = r->w[i] * t->sx[i];
            float h = r->h[i] * t->sy[i];
            SDL_Texture* texture = r->texture[i];

            bool is_out_of_camera = (x + w < c->x) || (x > c->x + c->w) || (y + h < c->y) || (y > c->y + c->h); 
            if (is_out_of_camera) {
                continue;
            }

            SDL_FRect rec_dest = { x, y, w, h };
            SDL_RenderCopyExF(
				renderer,
				texture,
				NULL,
				&rec_dest,
				angle,
				NULL,
				SDL_FLIP_NONE
			);
            texture = NULL;
        }
    }
}
