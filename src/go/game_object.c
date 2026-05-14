/**
* @file game_object.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "game_object.h"

game_object_t go(i32 x, i32 y, i32 w, i32 h) {
    game_object_t obj;
    obj.x = x;
    obj.y = y;
    obj.z = 0;
    obj.w = w;
    obj.h = h;
    obj.active = true;
    return obj;
}

game_object_t* go_new(i32 x, i32 y, i32 w, i32 h) {
    game_object_t* obj = malloc(sizeof(game_object_t));
    *obj = go(x, y, w, h);
    return obj;
}

box_collider_t go_get_collider(const game_object_t* obj) {
    return box_collider(obj->x, obj->y, obj->w, obj->h);
}
