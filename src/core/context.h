/**
* @file context.h
* @author Hudson Schumaker
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../pch.h"

/**
 * Initializes the context.
 * @return 0 on success, non-zero on failure
 */
int ctx_init(void);

/**
 * Gets the SDL window.
 * @return The SDL window
 */
SDL_Window* ctx_get_window(void);

/**
 * Gets the SDL renderer.
 * @return The SDL renderer
 */
SDL_Renderer* ctx_get_renderer(void);

/**
 * Checks if the context is initialized.
 * @return 1 if initialized, 0 otherwise
 */
u8 ctx_is_initialized(void);

/**
 * Checks if the video subsystem is initialized.
 * @return 1 if initialized, 0 otherwise
 */
u8 ctx_is_video_initialized(void);

/**
 * Checks if the window is initialized.
 * @return 1 if initialized, 0 otherwise
 */
u8 ctx_is_window_initialized(void);

/**
 * Checks if the renderer is initialized.
 * @return 1 if initialized, 0 otherwise
 */
u8 ctx_is_renderer_initialized(void);

/**
 * Checks if the image subsystem is initialized.
 * @return 1 if initialized, 0 otherwise
 */
u8 ctx_is_image_initialized(void);

/**
 * Checks if the audio subsystem is initialized.
 * @return 1 if initialized, 0 otherwise
 */
u8 ctx_is_audio_initialized(void);

/**
 * Checks if the TTF subsystem is initialized.
 * @return 1 if initialized, 0 otherwise
 */
u8 ctx_is_ttf_initialized(void);

/**
 * Quits the context and cleans up resources.
 */
void ctx_quit(void);
