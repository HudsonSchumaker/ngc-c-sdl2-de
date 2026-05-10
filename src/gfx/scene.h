/**
* @file scene.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef struct {
    void (*load)(void);    // Load the scene
    void (*input)(void);   // Handle input
    void (*update)(void);  // Update the scene
    void (*render)(void);  // Render the scene
	u8   (*run)(void);     // Game Loop for the scene
    void (*unload)(void);  // Unload the scene
} scene_t;

u8 scene_set_scene(scene_t* scene);
void scene_begin_render(void);
void scene_end_render(void);
