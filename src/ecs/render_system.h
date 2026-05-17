/**
* @file render_system.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"
#include "texture.h"
#include "transform.h"

void render_system(transform_pool_t* t, texture_pool_t* r);
