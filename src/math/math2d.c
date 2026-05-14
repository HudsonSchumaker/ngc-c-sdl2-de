/**
* @file math2d.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "math2d.h"
static f32 sin_table[SIN_COS_LUT_SIZE];
static f32 cos_table[SIN_COS_LUT_SIZE];
static u16 atan_table[ATAN_LUT_SIZE + 1];

void build_trigo_tables(void) {
    for (i32 i = 0; i < SIN_COS_LUT_SIZE; i++) {
        f32 angle =  ((f32)i / SIN_COS_LUT_SIZE) * TWO_PI_F;
        sin_table[i] = sinf(angle);
        cos_table[i] = cosf(angle);
    }

    for (i32 i = 0; i <= ATAN_LUT_SIZE; ++i) {
        f32 ratio = (f32)i / (f32)ATAN_LUT_SIZE;
        atan_table[i] = (u16)(atanf(ratio) * ((f32)SIN_COS_LUT_SIZE / TWO_PI_F));
    }
}

i32 de_atanf(i32 dy, i32 dx) {
    if (dx == 0 && dy == 0) {
        return 0;
    }

    i32 adx = dx < 0 ? -dx : dx;
    i32 ady = dy < 0 ? -dy : dy;

    i32 base;
    if (adx >= ady) {
        i32 ratio = (ady * ATAN_LUT_SIZE) / (adx == 0 ? 1 : adx);
        base = atan_table[ratio];
    } else {
        i32 ratio = (adx * ATAN_LUT_SIZE) / (ady == 0 ? 1 : ady);
        base = 256 - atan_table[ratio];
    }

    if (dx >= 0 && dy >= 0) return base;
    if (dx < 0 && dy >= 0) return 512 - base;
    if (dx < 0 && dy < 0) return 512 + base;
    return 1024 - base;
}

f32 de_sinf(i32 angle) {
    return sin_table[angle & ANGLE_MASK];
}

f32 de_cosf(i32 angle) {
    return cos_table[angle & ANGLE_MASK];
}
