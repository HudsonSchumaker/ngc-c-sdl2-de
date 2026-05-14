/**
* @file engine.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

void engine_init(void);
void engine_quit(void);

f32 engine_get_delta_time(void);
f32 engine_calculate_delta_time(void);
