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
    int32_t x;
    int32_t y;
    int16_t z;
    int32_t w;
    int32_t h;
    bool active;
} game_object_t;

game_object_t go_new(int32_t x, int32_t y, int32_t w, int32_t h);
box_collider_t go_get_collider(const game_object_t* obj);
