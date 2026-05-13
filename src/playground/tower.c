/**
* @file tower.c
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "tower.h"
#include "../gfx/gfx.h"
#include "../math/de_math.h"

tower_t tower(int x, int y, int w, int h, int range, int damage, int fire_rate) {
    tower_t t;
    t.x = x;
    t.y = y;
    t.w = w;
    t.h = h;
    t.z = 0;
    t.range = range;
    t.damage = damage;
    t.fire_rate = fire_rate;
    t.cooldown = 0;
    t.active = true;
    t.angle = 0.0f;
    t.texture = NULL; // Set this to your tower texture
    return t;
}

void tower_update(tower_t* tower, enemy_t* enemy, float delta_time){
    if (!tower->active) return;

    if (tower->cooldown > 0.0f) {
        tower->cooldown -= delta_time;
        if (tower->cooldown < 0.0f) {
            tower->cooldown = 0.0f;
        }
    }

    int tower_cx = tower->x + (tower->w >> 1);
    int tower_cy = tower->y + (tower->h >> 1);
    int enemy_cx = (int)enemy->x + (enemy->w >> 1);
    int enemy_cy = (int)enemy->y + (enemy->h >> 1);

    int dx = enemy_cx - tower_cx;
    int dy = enemy_cy - tower_cy;

    int dist_sq = dx * dx + dy * dy;
    int range_sq = tower->range * tower->range;

    if (dist_sq > range_sq) {
        return;
    }

    tower->angle = atan2_table(dy, dx);
    if (tower->cooldown <= 0.0f) {
        float vx = cosf_table(tower->angle);
        float vy = sinf_table(tower->angle);

        // spawn projectile here using vx, vy
        // or apply instant-hit damage here

        tower->cooldown = 1.0f / (float)tower->fire_rate;
    }
}

void tower_render(const tower_t* tower) {
    if (!tower->active) return;

    if (tower->texture) {
        double angle_deg = ((double)tower->angle * 360.0) / (double)SIN_COS_LUT_SIZE;
        gfx_render_texture_rotated(tower->texture, tower->x, tower->y, tower->w, tower->h, angle_deg);
    }
}
