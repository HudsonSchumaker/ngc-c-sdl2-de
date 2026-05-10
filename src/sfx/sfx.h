/**
* @file sfx.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

Mix_Chunk* sfx_load_sound(const uint8_t* data, const size_t size);
Mix_Music* sfx_load_music(const uint8_t* data, const size_t size);

int sfx_play_sound(Mix_Chunk* sound);
int sfx_play_music(Mix_Music* music, int loops);

void sfx_pause_music();
void sfx_unpause_music();
void sfx_stop_music();
