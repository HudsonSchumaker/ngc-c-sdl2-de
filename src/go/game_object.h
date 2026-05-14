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
    i32 x;
    i32 y;
    i32 z;
    i32 w;
    i32 h;
    bool active;
} game_object_t;

game_object_t go(i32 x, i32 y, i32 w, i32 h);
game_object_t* go_new(i32 x, i32 y, i32 w, i32 h);
box_collider_t go_get_collider(const game_object_t* obj);
