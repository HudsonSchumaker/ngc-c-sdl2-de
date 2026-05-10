/**
* @file label.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "label.h"
#include "../gfx/gfx.h"
#include "../gfx/color.h"
#include "../core/context.h"

label_t label(int x, int y, const char* text) {
    label_t label;
    label.text = strdup(text);
    label.x = x;
    label.y = y;
    label.w = 0;
    label.h = 0;
    label.font_size = 16;
    label.texture = NULL;
    label.color = color_white();
    label.visible = true;
    return label;
}

label_t* label_new(int x, int y, const char* text) {
    label_t* heap_label = malloc(sizeof(label_t));
    *heap_label = label(x, y, text);
    return heap_label;
}

void label_set_color(label_t* label, color_t color) {
    label->color = color;
}

void label_set_font_size(label_t* label, uint8_t font_size, const uint8_t* data, size_t size) {
    label->font_size = font_size;
    if (label->texture) {
        SDL_DestroyTexture(label->texture);
    }
    label->texture = gfx_create_text(data, size, label->text, font_size, label->color);
    SDL_QueryTexture(label->texture, NULL, NULL, &label->w, &label->h);
}

void label_render(const label_t* label) {
    if (label->visible && label->texture) {     
        SDL_Rect rect = { label->x, label->y, label->w, label->h };
        SDL_RenderCopy(ctx_get_renderer(), label->texture, NULL, &rect);
    }
}

void label_set_on_center(label_t* label) {
    SDL_Rect rect = gfx_get_texture_size(label->texture);
    label->x = (WINDOW_WIDTH - rect.w)  * DIV2;
    label->y = (WINDOW_HEIGHT - rect.h) * DIV2;
}

void label_set_horizontal_center(label_t* label) {
    SDL_Rect rect = gfx_get_texture_size(label->texture);
    label->x = (WINDOW_WIDTH - rect.w) * DIV2;
}
