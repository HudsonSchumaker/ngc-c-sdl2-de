/**
* @file de_math.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

i32 min(i32 a, i32 b);
i32 max(i32 a, i32 b);
i32 wrap(i32 value, i32 min_val, i32 max_val);
i32 clamp(i32 value, i32 min_val, i32 max_val);
i32 distance_between_points(i32 x1, i32 y1, i32 x2, i32 y2);

void build_trigo_tables(void);
i32 atan2_table(i32 dy, i32 dx);
f32 sinf_table(i32 angle);
f32 cosf_table(i32 angle);

f32 minf(f32 a, f32 b);
f32 maxf(f32 a, f32 b);
f32 randf(f32 min, f32 max);
f32 wrapf(f32 value, f32 min_val, f32 max_val);
f32 clampf(f32 value, f32 min_val, f32 max_val);
f32 rsqrtf(f32 number);
f32 fsqrtf(f32 number);
f32 deg_to_radf(f32 degrees);
f32 rad_to_degf(f32 radians);
f32 normalize_anglef(f32 angle);
f32 smoothstepf(f32 edge0, f32 edge1, f32 x);
f32 inverse_lerpf(f32 a, f32 b, f32 value);
f32 interpolatef(f32 start, f32 end, f32 t);
f32 distance_between_pointsf(f32 x1, f32 y1, f32 x2, f32 y2);
