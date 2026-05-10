/**
* @file context.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "context.h"
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static bool started = false;

int ctx_init(void) {
    if (started) {
        return 0; // Already initialized
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        return -1;
    }

    window = SDL_CreateWindow(
        "dodoi-engine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        ctx_quit();
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        ctx_quit();
        return -1;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        ctx_quit();
        return 1;
    }

    if (Mix_OpenAudio(32000, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        ctx_quit();
        return 1;
    }

    if (TTF_Init() == -1) {
        ctx_quit();
        return 1;
    }

    started = true;
    return 0;
}

SDL_Window* ctx_get_window(void) {
    return window;
}

SDL_Renderer* ctx_get_renderer(void) {
    return renderer;
}

void ctx_quit(void) {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = NULL;
    }
    
    Mix_HaltChannel(-1);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    started = false;
}
