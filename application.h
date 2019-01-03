#ifndef APPLICATION_H
#define APPLICATION_H

#define WINDOW_TITLE "Example OpenGL Context"
#define WINDOW_W 600
#define WINDOW_H 1000
#define TIME_STEP 16

#include <SDL2/SDL.h>

void Application_Initialise();

void Application_Cleanup();

void Application_TimeStep();

void Application_DrawFrame();

void Application_HandleKeyPress(const SDL_KeyboardEvent *event);

void Application_HandleKeyRelease(const SDL_KeyboardEvent *event);

#endif
