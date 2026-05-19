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

/**
 * @brief A pool of properties for enemy entities.
 */
typedef struct {
    f32 speed[MAX_ENTITIES];
    f32 health[MAX_ENTITIES];
} enemy_pool_t;

/**
 * @brief Creates an enemy entity and initializes its components and properties.
 * @param enemy_pool A pointer to the enemy pool where the enemy's properties will be stored
 * @param x The x-coordinate where the enemy will be placed
 * @param y The y-coordinate where the enemy will be placed
 */
void enemy_create(enemy_pool_t* enemy_pool, i32 x, i32 y);

void enemy_move(enemy_pool_t* enemy_pool, f32 delta_time);
