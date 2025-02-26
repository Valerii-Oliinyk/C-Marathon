#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "../player/player.h"
#include "../levels/level.h"
#include "utils.h"

typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
    GAME_STATE_EXIT
} GameState;

extern GameState game_state;

extern int game_is_running;
extern int key_states[SDL_NUM_SCANCODES];  // Add this line

int game_init();
void game_update();
void game_render();
void game_cleanup();

#endif
