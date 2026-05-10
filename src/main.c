/**
* @file main.c
* @author Hudson Schumaker
* @brief Defines the entry point of the game.
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "pch.h"
#include "core/engine.h"

int main(int argc, char **argv) {
    engine_init();
    engine_quit();
    return 0;
}
