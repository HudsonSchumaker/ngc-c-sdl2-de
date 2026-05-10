/**
* @file parallax_vertical.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "gfx.h"
#include "../core/context.h"
#include "parallax_vertical.h"

parallax_vertical_t parallax_vertical_new(const uint8_t* parallax_data, const size_t parallax_size) {
    parallax_vertical_t parallax;
    parallax.texture = gfx_load_texture(parallax_data, parallax_size);
    
    SDL_QueryTexture(parallax.texture, NULL, NULL, &parallax.size.x, &parallax.size.y);

    parallax.rect_a = (SDL_Rect){ 0, 0, parallax.size.x, parallax.size.y };
    parallax.rect_b = (SDL_Rect){ 0, -parallax.size.y, parallax.size.x, parallax.size.y };
    
    return parallax;
}

parallax_vertical_t parallax_vertical_2new(const uint8_t* bg_data, const size_t bg_size, const uint8_t* parallax_data, const size_t parallax_size) {
    parallax_vertical_t parallax;
    parallax.background = gfx_load_texture(bg_data, bg_size);
    parallax.bg_rect = gfx_get_texture_size(parallax.background);
    
    parallax.texture = gfx_load_texture(parallax_data, parallax_size);
    SDL_QueryTexture(parallax.texture, NULL, NULL, &parallax.size.x, &parallax.size.y);
    
    parallax.rect_a = (SDL_Rect){ 0, 0, parallax.size.x, parallax.size.y };
    parallax.rect_b = (SDL_Rect){ 0, -parallax.size.y, parallax.size.x, parallax.size.y };
    
    return parallax;
}

void parallax_vertical_update(parallax_vertical_t* parallax) {    
    if (parallax->rect_a.y >= parallax->size.y) {
        parallax->rect_a.x = 0;
        parallax->rect_a.y = 0;
        parallax->rect_a.w = parallax->size.x;
        parallax->rect_a.h = parallax->size.y;
        
        parallax->rect_b.x = 0;
        parallax->rect_b.y = -parallax->size.y;
        parallax->rect_b.w = parallax->size.x;
        parallax->rect_b.h = parallax->size.y;
    }
    
    parallax->rect_a.y += 1;
    parallax->rect_b.y += 1;
}

void parallax_vertical_render(const parallax_vertical_t* parallax) {
    if (parallax->background) {
        SDL_RenderCopy(ctx_get_renderer(), parallax->background, NULL, &parallax->bg_rect);
    }
    
    SDL_RenderCopy(ctx_get_renderer(), parallax->texture, NULL, &parallax->rect_a);
    SDL_RenderCopy(ctx_get_renderer(), parallax->texture, NULL, &parallax->rect_b);
}
