/**
* @file label.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

typedef struct {
    short rows;
    short cols;
    short cell_width;
    short cell_height;
} grid_t;

grid_t grid(short rows, short cols, short cell_width, short cell_height);
grid_t* grid_new(short rows, short cols, short cell_width, short cell_height);
void grid_render(grid_t* grid);
