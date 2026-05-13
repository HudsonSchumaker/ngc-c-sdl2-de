/**
* @file tower.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "enemy.h"
#include "../pch.h"

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int z;
    int range;
    int damage;
    int fire_rate;
    int cooldown;
    bool active;
    int angle;
    SDL_Texture* texture;
} tower_t;

tower_t tower(int x, int y, int w, int h, int range, int damage, int fire_rate);
void tower_update(tower_t* tower, enemy_t* enemy, float delta_time);
void tower_render(const tower_t* tower);
