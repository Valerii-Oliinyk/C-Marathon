#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "../player/player.h" 

void process_input(Player *player, SDL_Event *event);

#endif
