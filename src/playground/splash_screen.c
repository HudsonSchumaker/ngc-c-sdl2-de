/**
* @file splash_screen.c
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "../gfx/gfx.h"
#include "splash_screen.h"
#include "../core/engine.h"
#include "../core/context.h"
#include "logo_png.h"

static bool running = false;
static scene_t* splash_screen = NULL;
static SDL_Texture* logoTexture = NULL;
static SDL_Rect rect = { 0, 0, 0, 0 };

void splash_screen_init(void) {
    splash_screen = (scene_t*)malloc(sizeof(scene_t));
    if (splash_screen == NULL) {
        exit(EXIT_FAILURE);
    }

    splash_screen->load   = splash_screen_load;
    splash_screen->input  = splash_screen_input;
    splash_screen->update = splash_screen_update;
    splash_screen->render = splash_screen_render;
    splash_screen->run    = splash_screen_run;
    splash_screen->unload = splash_screen_unload;
}

void splash_screen_load(void) {
    logoTexture = gfx_load_texture(logo_png, logo_png_size);  

    SDL_QueryTexture(logoTexture, NULL, NULL, &rect.w, &rect.h);
    rect.x = (WINDOW_WIDTH - rect.w) * DIV2;
    rect.y = (WINDOW_HEIGHT - rect.h) * DIV2;
    running = true;
}

void splash_screen_input(void) {}

void splash_screen_update(void) {}

void splash_screen_render(void) {
    scene_begin_render();
    {
        SDL_Renderer* renderer = ctx_get_renderer();
        SDL_RenderCopy(renderer, logoTexture, NULL, &rect);
    }
    scene_end_render();
}

u8 splash_screen_run(void) {
    while (running) {
        splash_screen_input();
        splash_screen_update();
        splash_screen_render();
        engine_calculate_delta_time();
    }
    return 1;
}

void splash_screen_unload(void) {
    if (logoTexture != NULL) {
        SDL_DestroyTexture(logoTexture);
        logoTexture = NULL;
    }

    free(splash_screen);
    splash_screen = NULL;
}

scene_t* splash_screen_get_scene(void) {
    return splash_screen;
}
