/**
* @file game_object.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"
#include "box_collider.h"

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int h;
    bool active;
} game_object_t;

game_object_t go(int x, int y, int w, int h);
game_object_t* go_new(int x, int y, int w, int h);
box_collider_t go_get_collider(const game_object_t* obj);
