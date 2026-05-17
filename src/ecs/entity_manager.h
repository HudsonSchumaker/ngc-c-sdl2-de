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

static inline void entity_manager_init(entity_manager_t* em) {
    em->next = 0;
    for (u16 i = 0; i < MAX_ENTITIES; i++) {
        em->alive[i] = false;
    }
}

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

static inline void entity_destroy(entity_manager_t* em, entity_t e) { 
    em->alive[e] = false;
    if (e < em->next) {
        em->next = e;
    }
}
