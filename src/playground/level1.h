/**
* @file level.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"
#include "../gfx/scene.h"

void level1_init(void);
void level1_load(void);
void level1_input(void);
void level1_update(void);
void level1_render(void);
u8   level1_run(void);
void level1_unload(void);

scene_t* level1_get_scene(void);