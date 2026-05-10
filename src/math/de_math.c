/**
* @file de_math.c
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "de_math.h"

int min(int32_t a, int32_t b) {
    return (a < b) ? a : b;
}

int max(int32_t a, int32_t b) {
    return (a > b) ? a : b;
}

int wrap(int32_t value, int32_t min_val, int32_t max_val) {
    int32_t range = max_val - min_val + 1;
    if (range <= 0) return min_val; 
    int32_t wrapped_value = (value - min_val) % range;
    if (wrapped_value < 0) wrapped_value += range;
    return wrapped_value + min_val;
}

int clamp(int32_t value, int32_t min_val, int32_t max_val) {
    if (value < min_val) return min_val;
    if (value > max_val) return max_val;
    return value;
}

int distance_between_points(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    int32_t dx = x2 - x1;
    int32_t dy = y2 - y1;
    return (int32_t)sqrtf((float)(dx * dx + dy * dy));
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

    i =* (long*) &y;
    i = 0x5f3759df - (i >> 1);
    y =* (float*) &i;

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
    return sqrtf(dx * dx + dy * dy);
}
