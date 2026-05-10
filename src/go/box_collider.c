/**
* @file box_collider.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "box_collider.h"

box_collider_t box_collider_new(int32_t x, int32_t y, int32_t w, int32_t h) {
    box_collider_t collider;
    collider.x = x;
    collider.y = y;
    collider.w = w;
    collider.h = h;
    return collider;
}

bool box_collider_collide(const box_collider_t* a, const box_collider_t* b) {
    return (a->x < b->x + b->w &&
            a->x + a->w > b->x &&
            a->y < b->y + b->h &&
            a->y + a->h > b->y
        );
}

bool box_collider_contains(const box_collider_t* collider, int32_t px, int32_t py) {
    return (px >= collider->x &&
            px <= collider->x + collider->w &&
            py >= collider->y &&
            py <= collider->y + collider->h
        );
}
