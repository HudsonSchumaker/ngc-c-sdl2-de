/**
 * @file main.c
 * @brief Defines the entry point of the game.
 * @author Hudson Schumaker
 * @version 1.0.0
 *
 * NGC specs
 * CPU: IBM Gekko @486 MHz
 * GPU: ATI Flipper @162 MHz
 * RAM: 24 MB
 * VRAM: 3 MB
 *
 * Dodoi-Engine is a game engine developed by Dodoi-Lab.
 * @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "app.h"

/**
 * @brief The entry point of the game.
 * @param argc The number of command-line arguments
 * @param argv The array of command-line arguments
 * @return Exit status of the program
*/
int main(int argc, char** argv) {
    app_start();
    return 0;
}
