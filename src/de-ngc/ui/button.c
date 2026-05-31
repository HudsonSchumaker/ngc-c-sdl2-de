/**
 * @file button.c
 * @author Hudson Schumaker
 *
 * Dodoi-Engine is a game engine developed by Dodoi-Lab.
 * @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "button.h"
#include "../gfx/gfx.h"
#include "../core/context.h"

button_t button(i32 x, i32 y) {
    button_t button;
    button.x = x;
    button.y = y;
    button.w = 0;
    button.h = 0;
    button.texture = NULL;
    button.onclick = NULL;
    button.visible = true;
    return button;
}

button_t* button_new(i32 x, i32 y) {
    button_t* heap_button = malloc(sizeof(button_t));
    *heap_button = button(x, y);
    return heap_button;
}

void button_set_source(button_t* button, const u8* data, size_t size) {
    button->texture = gfx_load_texture(data, size);
    SDL_QueryTexture(button->texture, NULL, NULL, &button->w, &button->h);
}

void button_set_onclick(button_t* button, button_onclick_callback_t callback) {
    button->onclick = callback;
}

void button_render(const button_t* button) {
    if (button->visible) {
        SDL_Rect rect = { button->x, button->y, button->w, button->h };
        SDL_RenderCopy(ctx_get_renderer(), button->texture, NULL, &rect);
    }
}
