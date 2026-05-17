/**
* @file transform.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef struct {
    f32 px[MAX_ENTITIES];
    f32 py[MAX_ENTITIES];
    f32 sx[MAX_ENTITIES];
    f32 sy[MAX_ENTITIES];
    i32 ra[MAX_ENTITIES]; 
} transform_pool_t;
