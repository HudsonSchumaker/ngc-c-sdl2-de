/**
* @file collision.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"
#include "../math/math2d.h"

INLINE bool point_in_rect(i32 px, i32 py, i32 rx, i32 ry,i32 rw, i32 rh) {
    return (
        px >= rx &&
        px <= rx + rw &&
        py >= ry &&
        py <= ry + rh
    );
}

INLINE bool rect_intersects(i32 ax, i32 ay, i32 aw, i32 ah, i32 bx, i32 by, i32 bw, i32 bh) {
    return !(
        ax + aw < bx ||
        ax > bx + bw ||
        ay + ah < by ||
        ay > by + bh
    );
}

INLINE bool circle_intersects(vec2_t a, i32 ra, vec2_t b,i32 rb) {
    i32 rr = ra + rb;
    return vec2_distance_sq(a, b) <= (rr * rr);
}
