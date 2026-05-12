/**
* @file gfx.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "gfx.h"
#include "../core/context.h"

SDL_Texture* gfx_load_texture(const uint8_t* data, const size_t size) {
    SDL_RWops* rw = SDL_RWFromMem((void*)data, size);
    SDL_Texture* texture = IMG_LoadTexture_RW(ctx_get_renderer(), rw, 1);
    return texture;
}

SDL_Texture* gfx_create_text(const uint8_t* data, const size_t size, const char* text, uint8_t text_size, color_t color) {
    SDL_RWops* rw = SDL_RWFromMem((void*)data, size);
    TTF_Font* font = TTF_OpenFontRW(rw, 1, text_size);

    SDL_Color sdl_color = color_to_sdl_color(color);

    SDL_Surface* surface = TTF_RenderText_Blended(font, text, sdl_color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ctx_get_renderer(), surface);
    
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    return texture;
}

SDL_Rect gfx_get_texture_size(SDL_Texture* texture) {
    SDL_Rect rect;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    rect.x = 0;
    rect.y = 0;
    return rect;
}

SDL_FRect gfx_get_texture_fsize(SDL_Texture* texture) {
    SDL_FRect rect;
    SDL_QueryTexture(texture, NULL, NULL, (int*)&rect.w, (int*)&rect.h);
    rect.x = 0.0f;
    rect.y = 0.0f;
    return rect;
}

void gfx_render_texture(SDL_Texture* texture, int x, int y, int w, int h) {
    SDL_Rect dest = {x, y, w, h};
    SDL_RenderCopy(ctx_get_renderer(), texture, NULL, &dest);
}

void gfx_draw_line(int x0, int y0, int x1, int y1, color_t color) {
    uint8_t prev_r, prev_g, prev_b, prev_a;
    SDL_GetRenderDrawColor(ctx_get_renderer(), &prev_r, &prev_g, &prev_b, &prev_a);

    SDL_SetRenderDrawColor(ctx_get_renderer(), color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(ctx_get_renderer(), x0, y0, x1, y1);
    
    SDL_SetRenderDrawColor(ctx_get_renderer(), prev_r, prev_g, prev_b, prev_a);
}

void gfx_draw_circle(int cx, int cy, int radius, color_t color) {
    uint8_t prev_r, prev_g, prev_b, prev_a;
    SDL_GetRenderDrawColor(ctx_get_renderer(), &prev_r, &prev_g, &prev_b, &prev_a);
    SDL_SetRenderDrawColor(ctx_get_renderer(), color.r, color.g, color.b, color.a);
    
    // Draw
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        SDL_RenderDrawPoint(ctx_get_renderer(), cx + x, cy + y);
        SDL_RenderDrawPoint(ctx_get_renderer(), cx + y, cy + x);
        SDL_RenderDrawPoint(ctx_get_renderer(), cx - y, cy + x);
        SDL_RenderDrawPoint(ctx_get_renderer(), cx - x, cy + y);
        SDL_RenderDrawPoint(ctx_get_renderer(), cx - x, cy - y);
        SDL_RenderDrawPoint(ctx_get_renderer(), cx - y, cy - x);
        SDL_RenderDrawPoint(ctx_get_renderer(), cx + y, cy - x);
        SDL_RenderDrawPoint(ctx_get_renderer(), cx + x, cy - y);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }

    SDL_SetRenderDrawColor(ctx_get_renderer(), prev_r, prev_g, prev_b, prev_a);
}

void gfx_draw_fill_circle(int cx, int cy, int radius, color_t color) {
    uint8_t prev_r, prev_g, prev_b, prev_a;
    SDL_GetRenderDrawColor(ctx_get_renderer(), &prev_r, &prev_g, &prev_b, &prev_a);
    SDL_SetRenderDrawColor(ctx_get_renderer(), color.r, color.g, color.b, color.a);
    
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                SDL_RenderDrawPoint(ctx_get_renderer(), cx + x, cy + y);
            }
        }
    }

    SDL_SetRenderDrawColor(ctx_get_renderer(), prev_r, prev_g, prev_b, prev_a);
}

void gfx_draw_dashed_circle(const int cx, const int cy, const int radius, const int dash_length, const color_t color) {
    uint8_t prev_r, prev_g, prev_b, prev_a;
    SDL_GetRenderDrawColor(ctx_get_renderer(), &prev_r, &prev_g, &prev_b, &prev_a);
    SDL_SetRenderDrawColor(ctx_get_renderer(), color.r, color.g, color.b, color.a);
    
    const int total_segments = (int)(radius * M_PI / dash_length);
    const float angle_increment = TWO_PI / total_segments;

     for (short i = 0; i < total_segments; ++i) {
        float angle = angle_increment * i;

        int x1 = (int)(cx + radius * cosf(angle));
        int y1 = (int)(cy + radius * sinf(angle));

        angle = angle_increment * (i + 1);

        int x2 = (int)(cx + radius * cosf(angle));
        int y2 = (int)(cy + radius * sinf(angle));

        if (i % 2 == 0) {
            SDL_RenderDrawLine(ctx_get_renderer(), x1, y1, x2, y2);
        }
    }

    SDL_SetRenderDrawColor(ctx_get_renderer(), prev_r, prev_g, prev_b, prev_a);
}

void gfx_draw_box(SDL_Rect rect, color_t color) {
    uint8_t prev_r, prev_g, prev_b, prev_a;
    SDL_GetRenderDrawColor(ctx_get_renderer(), &prev_r, &prev_g, &prev_b, &prev_a);
    SDL_SetRenderDrawColor(ctx_get_renderer(), color.r, color.g, color.b, color.a);
    
    SDL_RenderDrawRect(ctx_get_renderer(), &rect);
    SDL_SetRenderDrawColor(ctx_get_renderer(), prev_r, prev_g, prev_b, prev_a);
}

void gfx_draw_fbox(SDL_FRect rect, color_t color) {
    uint8_t prev_r, prev_g, prev_b, prev_a;
    SDL_GetRenderDrawColor(ctx_get_renderer(), &prev_r, &prev_g, &prev_b, &prev_a);
    SDL_SetRenderDrawColor(ctx_get_renderer(), color.r, color.g, color.b, color.a);
    
    SDL_RenderDrawRectF(ctx_get_renderer(), &rect);
    SDL_SetRenderDrawColor(ctx_get_renderer(), prev_r, prev_g, prev_b, prev_a);
}

void gfx_draw_fill_box(SDL_Rect rect, color_t color) {
    uint8_t prev_r, prev_g, prev_b, prev_a;
    SDL_GetRenderDrawColor(ctx_get_renderer(), &prev_r, &prev_g, &prev_b, &prev_a);
    SDL_SetRenderDrawColor(ctx_get_renderer(), color.r, color.g, color.b, color.a);
    
    SDL_RenderFillRect(ctx_get_renderer(), &rect);
    SDL_SetRenderDrawColor(ctx_get_renderer(), prev_r, prev_g, prev_b, prev_a);
}

void gfx_draw_fill_fbox(SDL_FRect rect, color_t color) {
    uint8_t prev_r, prev_g, prev_b, prev_a;
    SDL_GetRenderDrawColor(ctx_get_renderer(), &prev_r, &prev_g, &prev_b, &prev_a);
    SDL_SetRenderDrawColor(ctx_get_renderer(), color.r, color.g, color.b, color.a);
    
    SDL_RenderFillRectF(ctx_get_renderer(), &rect);
    SDL_SetRenderDrawColor(ctx_get_renderer(), prev_r, prev_g, prev_b, prev_a);
}

void gfx_draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, color_t color) {
    gfx_draw_line(x1, y1, x2, y2, color);
    gfx_draw_line(x2, y2, x3, y3, color);
    gfx_draw_line(x3, y3, x1, y1, color);
}
