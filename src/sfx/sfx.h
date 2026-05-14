/**
* @file sfx.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

Mix_Chunk* sfx_load_sound(const u8* data, const size_t size);
Mix_Music* sfx_load_music(const u8* data, const size_t size);

i32 sfx_play_sound(Mix_Chunk* sound);
i32 sfx_play_music(Mix_Music* music, i32 loops);

void sfx_pause_music();
void sfx_unpause_music();
void sfx_stop_music();
