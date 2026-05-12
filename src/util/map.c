/**
* @file map.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "map.h"
#include "../gfx/gfx.h"

void map_load(map_t* map, const char* data[MAP_HEIGHT][MAP_WIDTH]) {
    for (short y = 0; y < MAP_HEIGHT; ++y) {
        for (short x = 0; x < MAP_WIDTH; ++x) {
            char type_char = data[y][x][0];
            short tex_id = atoi(&data[y][x][1]);

            if (type_char == 'p') {
                map->tiles[y][x].type = TILE_PATH;
            } else if (type_char == 'g') {
                map->tiles[y][x].type = TILE_GROUND;
            }
            map->tiles[y][x].texture_id = tex_id;
        }
    }
}

void map_render(const map_t* map) {
    for (short y = 0; y < MAP_HEIGHT; ++y) {
        for (short x = 0; x < MAP_WIDTH; ++x) {
            short tex_id = map->tiles[y][x].texture_id;
            gfx_render_texture(map->textures[tex_id], x * MAP_TILE_SIZE, y * MAP_TILE_SIZE);
        }
    }
}
