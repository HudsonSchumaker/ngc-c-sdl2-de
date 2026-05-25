/**
* @file projectile.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../de-ngc/de.h"

typedef struct {
    f32 speed[MAX_ENTITIES];
    f32 damage[MAX_ENTITIES];
    f32 ox[MAX_ENTITIES];
    f32 oy[MAX_ENTITIES];
    f32 dx[MAX_ENTITIES];
    f32 dy[MAX_ENTITIES];
    f32 tx[MAX_ENTITIES];
    f32 ty[MAX_ENTITIES];
} projectile_pool_t;
