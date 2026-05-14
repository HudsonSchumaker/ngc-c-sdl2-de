/**
* @file pch.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

// Console-specific includes
#include <gccore.h>

// SDL2 includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef float   f32;
typedef double  f64;
typedef int32_t b32;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define H_WINDOW_WIDTH 320
#define H_WINDOW_HEIGHT 240

#define ATAN_LUT_SIZE 256
#define SIN_COS_LUT_SIZE 1024
#define ANGLE_MASK (SIN_COS_LUT_SIZE - 1)

#define MAP_WIDTH 20
#define MAP_HEIGHT 15
#define MAP_TILE_SIZE 32

#define DIV2   0.5f
#define DIV3   0.3333333333f
#define DIV4   0.25f
#define DIV5   0.2f
#define DIV6   0.1666666667f
#define DIV7   0.1428571429f
#define DIV8   0.125f
#define DIV9   0.1111111111f
#define DIV10  0.1f
#define DIV16  0.0625f
#define DIV32  0.03125f
#define DIV64  0.015625f
#define DIV128 0.0078125f

#define PI_F 3.1415927f
#define TWO_PI_F (PI_F * 2.0f)
#define HALF_PI_F (PI_F * 0.5f)
#define DIV_PI_180_F (PI_F / 180.0f)
#define DIV_180_PI_F (180.0f / PI_F)

typedef struct {
    u8 a: 1;
    u8 b: 1;
    u8 c: 1;
    u8 d: 1;
    u8 e: 1;
    u8 f: 1;
    u8 g: 1;
    u8 h: 1;
} byte_t;
