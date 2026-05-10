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
void ctx_quit(void);
