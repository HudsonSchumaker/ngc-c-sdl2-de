/**
* @file context.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

int ctx_init(void);
SDL_Window* ctx_get_window(void);
SDL_Renderer* ctx_get_renderer(void);

u8 ctx_is_initialized(void);
u8 ctx_is_video_initialized(void);
u8 ctx_is_window_initialized(void);
u8 ctx_is_renderer_initialized(void);
u8 ctx_is_image_initialized(void);
u8 ctx_is_audio_initialized(void);
u8 ctx_is_ttf_initialized(void);

void ctx_quit(void);
