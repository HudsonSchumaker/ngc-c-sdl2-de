/**
* @file image.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "image.h"
#include "../gfx/gfx.h"
#include "../gfx/color.h"
#include "../core/context.h"

image_t image(int x, int y) {
    image_t image;
    image.x = x;
    image.y = y;
    image.w = 0;
    image.h = 0;
    image.texture = NULL;
    image.color = color_white();
    image.visible = true;
    return image;
}

image_t* image_new(int x, int y) {
    image_t* heap_image = malloc(sizeof(image_t));
    *heap_image = image(x, y);
    return heap_image;
}
    
void image_set_source(image_t* image, const uint8_t* data, size_t size) {
    image->texture = gfx_load_texture(data, size);
    SDL_QueryTexture(image->texture, NULL, NULL, &image->w, &image->h);
}

void image_set_tint(image_t* image, color_t color) {
    image->color = color;
}

void image_render(const image_t* image) {
    if (image->visible) {
        SDL_SetTextureColorMod(image->texture, image->color.r, image->color.g, image->color.b);
        SDL_SetTextureAlphaMod(image->texture, image->color.a);
        
        SDL_Rect rect = { image->x, image->y, image->w, image->h };
        SDL_RenderCopy(ctx_get_renderer(), image->texture, NULL, &rect);
    }
}
