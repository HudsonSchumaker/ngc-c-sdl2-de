/**
* @file de_math.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

int min(int32_t a, int32_t b);
int max(int32_t a, int32_t b);
int wrap(int32_t value, int32_t min_val, int32_t max_val);
int clamp(int32_t value, int32_t min_val, int32_t max_val);
int distance_between_points(int32_t x1, int32_t y1, int32_t x2, int32_t y2);

float minf(float a, float b);
float maxf(float a, float b);
float randf(float min, float max);
float wrapf(float value, float min_val, float max_val);
float clampf(float value, float min_val, float max_val);
float rsqrtf(float number);
float fsqrtf(float number);
float deg_to_radf(float degrees);
float rad_to_degf(float radians);
float normalize_anglef(float angle);
float smoothstepf(float edge0, float edge1, float x);
float inverse_lerpf(float a, float b, float value);
float interpolatef(float start, float end, float t);
float distance_between_pointsf(float x1, float y1, float x2, float y2);
