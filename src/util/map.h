/**
* @file map.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef enum {
    TILE_PATH,
    TILE_GROUND
} map_tile_type_t;

typedef struct {
    map_tile_type_t type;
    short texture_id;
} map_tile_t;

typedef struct {
    SDL_Texture* textures[8];
    map_tile_t tiles[MAP_HEIGHT][MAP_WIDTH];
} map_t;

void map_load(map_t* map, const char* data[MAP_HEIGHT][MAP_WIDTH]);
void map_render(const map_t* map);
map_tile_type_t map_get_tile_type(const map_t* map, short x, short y);
