/**
* @file box_collider.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef struct {
    int x;
    int y;
    int w;
    int h;
} box_collider_t;

box_collider_t box_collider(i32 x, i32 y, i32 w, i32 h);
box_collider_t* box_collider_new(i32 x, i32 y, i32 w, i32 h);
bool box_collider_collide(const box_collider_t* a, const box_collider_t* b);
bool box_collider_contains(const box_collider_t* collider, i32 px, i32 py);
