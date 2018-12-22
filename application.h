#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>

void Application_Initialise();

void Application_Cleanup();

void Application_TimeStep();

void Application_DrawFrame();

void Application_HandleKeyPress(const SDL_KeyboardEvent *event);

void Application_HandleKeyRelease(const SDL_KeyboardEvent *event);

#endif
