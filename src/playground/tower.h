/**
 * @file tower.h
 * @author Hudson Schumaker
 * @version 1.0.0
 *
 * Dodoi-Engine is a game engine developed by Dodoi-Lab.
 * @copyright Copyright (c) 2024, Dodoi-Lab
 */
#pragma once
#include "../pch.h"

/**
 * @brief A pool of properties for tower entities.
 */
typedef struct {
    f32 range[MAX_ENTITIES];
    f32 damage[MAX_ENTITIES];
    f32 cooldown[MAX_ENTITIES];
    f32 fire_rate[MAX_ENTITIES];
    i8  level[MAX_ENTITIES];
} tower_pool_t;

/**
 * @brief Creates a tower entity and initializes its components and properties.
 * @param tower_pool A pointer to the tower pool where the tower's properties will be stored
 * @param x The x-coordinate where the tower will be placed
 * @param y The y-coordinate where the tower will be placed
 */
void tower_create(tower_pool_t* tower_pool, i32 x, i32 y);

/**
 * @brief Upgrades a tower, increasing its level, damage, range, and fire rate.
 * @param tower_pool A pointer to the tower pool where the tower's properties are stored
 * @param tower The entity ID of the tower to be upgraded
 */
void tower_upgrade(tower_pool_t* tower_pool, entity_t tower);
