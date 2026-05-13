/**
* @file de_math.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "de_math.h"
static float sin_table[SIN_COS_LUT_SIZE];
static float cos_table[SIN_COS_LUT_SIZE];
static unsigned short atan_table[ATAN_LUT_SIZE + 1];

void build_trigo_tables(void) {
    for (int i = 0; i < SIN_COS_LUT_SIZE; i++) {
        float angle =  ((float)i / SIN_COS_LUT_SIZE) * TWO_PI;
        sin_table[i] = sinf(angle);
        cos_table[i] = cosf(angle);
    }

    for (int i = 0; i <= ATAN_LUT_SIZE; ++i) {
        float ratio = (float)i / (float)ATAN_LUT_SIZE;
        atan_table[i] = (unsigned short)(atanf(ratio) * ((float)SIN_COS_LUT_SIZE / TWO_PI));
    }
}

int atan2_table(int dy, int dx) {
    if (dx == 0 && dy == 0) {
        return 0;
    }

    int adx = dx < 0 ? -dx : dx;
    int ady = dy < 0 ? -dy : dy;

    int base;
    if (adx >= ady) {
        int ratio = (ady * ATAN_LUT_SIZE) / (adx == 0 ? 1 : adx);
        base = atan_table[ratio];
    } else {
        int ratio = (adx * ATAN_LUT_SIZE) / (ady == 0 ? 1 : ady);
        base = 256 - atan_table[ratio];
    }

    if (dx >= 0 && dy >= 0) return base;
    if (dx < 0 && dy >= 0) return 512 - base;
    if (dx < 0 && dy < 0) return 512 + base;
    return 1024 - base;
}

float sinf_table(int angle) {
    return sin_table[angle & ANGLE_MASK];
}

float cosf_table(int angle) {
    return cos_table[angle & ANGLE_MASK];
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int wrap(int value, int min_val, int max_val) {
    int range = max_val - min_val + 1;
    if (range <= 0) return min_val; 
    int wrapped_value = (value - min_val) % range;
    if (wrapped_value < 0) wrapped_value += range;
    return wrapped_value + min_val;
}

int clamp(int value, int min_val, int max_val) {
    if (value < min_val) return min_val;
    if (value > max_val) return max_val;
    return value;
}

int distance_between_points(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    float distSq = (float)(dx * dx + dy * dy);
    float inv = rsqrtf(distSq);
    return (int)(distSq * inv);
}

float minf(float a, float b) {
    return (a < b) ? a : b;
}

float maxf(float a, float b) {
    return (a > b) ? a : b;
}

float randf(float min, float max) {
    return ((float)rand() / (float)RAND_MAX) * (max - min) + min;
}

float wrapf(float value, float min_val, float max_val) {
    float range = max_val - min_val;
    if (range <= 0.0f) return min_val; // Avoid division by zero
    float wrapped_value = fmodf(value - min_val, range);
    if (wrapped_value < 0.0f) wrapped_value += range; // Handle negative values
    return wrapped_value + min_val;
}

float clampf(float value, float min_val, float max_val) {
    if (value < min_val) return min_val;
    if (value > max_val) return max_val;
    return value;
}

float rsqrtf(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5f;

    x2 = number * 0.5f;
    y  = number;

    i = *(long*) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*) &i;

    y = y * (threehalfs - (x2 * y * y));
    return y;
}

float fsqrtf(float number) {
    return number * rsqrtf(number);
}

float deg_to_radf(float degrees) {
    return degrees * DIV_PI_180;
}

float rad_to_degf(float radians) {
    return radians * DIV_180_PI;
}

float normalize_anglef(float angle) {
    while (angle < 0.0f) angle += 360.0f;
    while (angle >= 360.0f) angle -= 360.0f;
    return angle;
}

float smoothstepf(float edge0, float edge1, float x) {
    if (x <= edge0) return 0.0f;
    if (x >= edge1) return 1.0f;
    x = (x - edge0) / (edge1 - edge0); // Normalize to [0, 1]
    return x * x * (3 - 2 * x); // Smoothstep formula
}

float inverse_lerpf(float a, float b, float value) {
    if (a == b) return 0.0f; // Avoid division by zero
    return (value - a) / (b - a);
}

float interpolatef(float start, float end, float t) {
    return start + (end - start) * t;
}

float distance_between_pointsf(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    float distSq = dx * dx + dy * dy;
    float inv = rsqrtf(distSq);
    return distSq * inv;
}
