/**
* @file engine.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

/**
 * Initializes the engine and its subsystems.
 */
void engine_init(void);

/**
 * Quits the engine and cleans up resources.
 */
void engine_quit(void);

/**
 * Gets the time elapsed since the last frame in seconds.
 * @return The delta time in seconds
 */
f32 engine_get_delta_time(void);

/**
 * Calculates the time elapsed since the last frame and updates the delta time.
 * @return The calculated delta time in seconds
 */
f32 engine_calculate_delta_time(void);
