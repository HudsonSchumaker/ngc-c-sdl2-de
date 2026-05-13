/**
* @file enemy.c
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "enemy.h"
#include "../gfx/gfx.h"

enemy_t enemy(float x, float y, int w, int h, int health, float speed) {
    enemy_t e;
    e.x = x;
    e.y = y;
    e.w = w;
    e.h = h;
    e.z = 0;
    e.health = health;
    e.speed = speed;
    e.active = true;
    e.texture = NULL; // Set this to your enemy texture
    return e;
}

void enemy_update(enemy_t* enemy, float delta_time) {
    if (!enemy->active) return;

    // Example movement logic (move right)
    enemy->x += enemy->speed * delta_time;
}

void enemy_render(const enemy_t* enemy) {
    if (!enemy->active) return;

    // Render the enemy using its texture and position
    if (enemy->texture) {
        SDL_FRect dest = { enemy->x, enemy->y, (float)enemy->w, (float)enemy->h };
        gfx_render_texture(enemy->texture, dest.x, dest.y, dest.w, dest.h);
    }
}
