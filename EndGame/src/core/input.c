#include "../../inc/core/game.h"
#include "../../inc/core/input.h"

void process_input(Player *player, SDL_Event *event) {
    const Uint8 *current_key_states = SDL_GetKeyboardState(NULL);
    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        key_states[i] = current_key_states[i];
    }

    SDL_PollEvent(event);

    switch (event->type) {
        case SDL_QUIT:
            game_is_running = FALSE;
            break;
        case SDL_KEYDOWN:
            if(event->key.keysym.sym == SDLK_ESCAPE) {
                game_is_running = FALSE;
            }
            break;
    }

    if (key_states[SDL_SCANCODE_LEFT] || key_states[SDL_SCANCODE_A]) {
        player->velX = -PLAYER_SPEED;
    } else if (key_states[SDL_SCANCODE_RIGHT] || key_states[SDL_SCANCODE_D]) {
        player->velX = PLAYER_SPEED;
    } else {
        player->velX = 0;
    }

    if (key_states[SDL_SCANCODE_SPACE] && player->onGround) {
        player->velY = PLAYER_JUMP_STRENGTH;
        player->onGround = 0;
    }
}
