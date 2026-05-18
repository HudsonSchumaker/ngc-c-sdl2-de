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

/**
 * @brief Represents a game object with position, size, and active state.
 */
typedef struct {
    i32 x;
    i32 y;
    i32 z;
    i32 w;
    i32 h;
    bool active;
} game_object_t;

/**
 * @brief Creates a new game object with the specified position and size.
 * @param x The X coordinate of the game object
 * @param y The Y coordinate of the game object
 * @param w The width of the game object
 * @param h The height of the game object
 * @return A new game_object_t struct initialized with the specified values and active state set to true
 */
game_object_t go(i32 x, i32 y, i32 w, i32 h);

/**
 * @brief Creates a new game object on the heap with the specified position and size.
 * @param x The X coordinate of the game object
 * @param y The Y coordinate of the game object
 * @param w The width of the game object
 * @param h The height of the game object
 * @return A pointer to a new game_object_t struct initialized with the specified values and active state set to true
 */
game_object_t* go_new(i32 x, i32 y, i32 w, i32 h);

/**
 * @brief Gets the box collider for a given game object.
 * @param obj A pointer to the game object
 * @return A box_collider_t struct representing the collider of the game object based on its position and size
 */
box_collider_t go_get_collider(const game_object_t* obj);
