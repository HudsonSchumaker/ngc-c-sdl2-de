/**
* @file math2d.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"
//----------------------------------------------------------------
// Lookup tables for trigonometric functions
//----------------------------------------------------------------
void build_trigo_tables(void);
i32 de_atanf(i32 dy, i32 dx);
f32 de_sinf(i32 angle);
f32 de_cosf(i32 angle);

//----------------------------------------------------------------
// Square root and inverse fast square root
//----------------------------------------------------------------
INLINE f32 rsqrtf(f32 number) {
    i64 i;
    f32 x2, y;
    const f32 threehalfs = 1.5f;

    x2 = number * 0.5f;
    y  = number;

    i = *(i64*) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(f32*) &i;

    y = y * (threehalfs - (x2 * y * y));
    return y;
}

INLINE f32 fsqrtf(f32 number) {
    return number * rsqrtf(number);
}

//----------------------------------------------------------------
// Vector2D struct and functions
//----------------------------------------------------------------
typedef union ALIGN32 {
    struct {
        f32 x;
        f32 y;
    };
    f32 v[2];
} vec2_t;

INLINE vec2_t vec2_create(f32 x, f32 y) {
    vec2_t v;
    v.x = x;
    v.y = y;
    return v;
}

INLINE vec2_t vec2_zero(void) {
    return vec2_create(0.0f, 0.0f);
}

INLINE vec2_t vec2_left(void) {
    return vec2_create(-1.0f, 0.0f);
}

INLINE vec2_t vec2_right(void) {
    return vec2_create(1.0f, 0.0f);
}

INLINE vec2_t vec2_up(void) {
    return vec2_create(0.0f, -1.0f);
}

INLINE vec2_t vec2_down(void) {
    return vec2_create(0.0f, 1.0f);
}

INLINE vec2_t vec2_add(vec2_t a, vec2_t b) {
    vec2_t r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

INLINE vec2_t vec2_sub(vec2_t a, vec2_t b) {
    vec2_t r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

INLINE vec2_t vec2_mul(vec2_t v, f32 s) {
    vec2_t r;
    r.x = v.x * s;
    r.y = v.y * s;
    return r;
}

INLINE f32 vec2_dot(vec2_t a, vec2_t b) {
    return (a.x * b.x) + (a.y * b.y);
}

INLINE f32 vec2_length_sq(vec2_t v) {
    return vec2_dot(v, v);
}

INLINE f32 vec2_length(vec2_t v) {
    f32 len_sq = vec2_length_sq(v);
    if (len_sq <= 0.0f) {
        return 0.0f;
    }

    return len_sq * rsqrtf(len_sq);
}

INLINE vec2_t vec2_normalize(vec2_t v) {
    f32 len_sq = vec2_length_sq(v);
    if (len_sq < EPSILON_F) {
        return vec2_zero();
    }

    f32 inv_len = rsqrtf(len_sq);
    vec2_t r;
    r.x = v.x * inv_len;
    r.y = v.y * inv_len;

    return r;
}

INLINE vec2_t vec2_rotate(vec2_t v, i32 angle) {
    f32 s = de_sinf(angle);
    f32 c = de_cosf(angle);

    vec2_t r;
    r.x = (v.x * c) - (v.y * s);
    r.y = (v.x * s) + (v.y * c);

    return r;
}

INLINE vec2_t vec2_move_forward(vec2_t position, i32 angle,f32 speed) {
    position.x += de_cosf(angle) * speed;
    position.y += de_sinf(angle) * speed;

    return position;
}

//----------------------------------------------------------------
// Math utility functions
//----------------------------------------------------------------
INLINE f32 minf(f32 a, f32 b) {
    return (a < b) ? a : b;
}

INLINE f32 maxf(f32 a, f32 b) {
    return (a > b) ? a : b;
}

INLINE f32 clampf(f32 v, f32 min, f32 max) {
    return minf(maxf(v, min), max);
}

INLINE f32 lerpf(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}

INLINE f32 absf(f32 v) {
    return (v < 0.0f) ? -v : v;
}

INLINE f32 randf(f32 min, f32 max) {
    return ((f32)rand() / (f32)RAND_MAX) * (max - min) + min;
}

INLINE f32 distance_pointsf(f32 x1, f32 y1, f32 x2, f32 y2) {
    f32 dx = x2 - x1;
    f32 dy = y2 - y1;

    f32 dist_sq = dx * dx + dy * dy;
    f32 inv = rsqrtf(dist_sq);
    return dist_sq * inv;
}

INLINE f32 distance_points_sqf(f32 x1, f32 y1, f32 x2, f32 y2) {
    f32 dx = x2 - x1;
    f32 dy = y2 - y1;
    return dx * dx + dy * dy;
}

INLINE f32 vec2_distance_sq(vec2_t a, vec2_t b) {
    f32 dx = b.x - a.x;
    f32 dy = b.y - a.y;
    return dx * dx + dy * dy;
}

INLINE f32 vec2_distance(vec2_t a, vec2_t b) {
    return fsqrtf(vec2_distance_sq(a, b));
}

INLINE f32 angle_between_pointsf(f32 x1, f32 y1, f32 x2, f32 y2) {
    f32 dx = x2 - x1;
    f32 dy = y2 - y1;
    return atan2f(dy, dx);
}

//----------------------------------------------------------------
// Angle utilities
//----------------------------------------------------------------
INLINE i32 wrap_angle(i32 angle) {
    return angle & ANGLE_MASK;
}

INLINE f32 deg2rad(f32 deg) {
    return deg * DEG_2_RAD_F;
}

INLINE f32 rad2deg(f32 rad) {
    return rad * RAD_2_DEG_F;
}
