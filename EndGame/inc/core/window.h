#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

extern SDL_Window *window;

int initialize_window();
void destroy_window();

#endif
