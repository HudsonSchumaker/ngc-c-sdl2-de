/**
* @file enemy.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef struct {
    float x;
    float y;
    int w;
    int h;
    int z;
    int health;
    float speed;
    bool active;
    SDL_Texture* texture;
} enemy_t;

enemy_t enemy(float x, float y, int w, int h, int health, float speed);
void enemy_update(enemy_t* enemy, float delta_time);
void enemy_render(const enemy_t* enemy);
