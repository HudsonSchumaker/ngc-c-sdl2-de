/**
* @file entity_manager.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef struct {
    bool alive[MAX_ENTITIES];
    u16 next;
} entity_manager_t;

/**
 * @brief Initializes the entity manager by setting all entities to not alive and resetting the next available entity index.
 * @param em A pointer to the entity manager to initialize.
 */
static inline void entity_manager_init(entity_manager_t* em) {
    em->next = 0;
    for (u16 i = 0; i < MAX_ENTITIES; i++) {
        em->alive[i] = false;
    }
}

/**
 * @brief Creates a new entity by finding the next available slot in the entity manager.
 * @param em A pointer to the entity manager.
 * @return The ID of the newly created entity, or UINT16_MAX if no available slots.
 */
static inline entity_t entity_create(entity_manager_t* em) {
    for (u16 i = em->next; i < MAX_ENTITIES; i++) {
        if (!em->alive[i]) {
            em->alive[i] = true;
            em->next = i + 1;
            return i;
        }
    }
    return UINT16_MAX;
}

/**
 * @brief Destroys an entity by marking it as not alive and updating the next available entity index if necessary.
 * @param em A pointer to the entity manager.
 * @param e The ID of the entity to destroy.
 */
static inline void entity_destroy(entity_manager_t* em, entity_t e) { 
    em->alive[e] = false;
    if (e < em->next) {
        em->next = e;
    }
}
