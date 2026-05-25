/**
 * @file radar_system.h
 * @author Hudson Schumaker
 *
 * Dodoi-Engine is a game engine developed by Dodoi-Lab.
 * @copyright Copyright (c) 2024, Dodoi-Lab
 */
#pragma once
#include "../de.h"
#include "entity_manager.h"

/**
 * @brief A radar system that processes entities with a specific source tag and identifies entities with a target tag within a certain range.
 * @param source The tag of the source entities to check from
 * @param target The tag of the target entities to check for
 */
void radar_system(tag_t source, tag_t target);
