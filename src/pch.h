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

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define H_WINDOW_WIDTH 320
#define H_WINDOW_HEIGHT 240

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

#define TWO_PI 6.28318530717958647692f
#define HALF_PI 1.57079632679489661923f
#define DIV_PI_180 0.01745329251994329577f
#define DIV_180_PI 57.2957795130823208768f
