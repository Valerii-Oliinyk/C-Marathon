#include "../../inc/core/render.h"
#include "../../inc/player/player.h"
#include "../../inc/menu/menu.h"
#include "../../inc/levels/level.h"
#include "../../inc/core/game.h"

void render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    switch (game_state) {
        case GAME_STATE_MENU:
            menu_render();
            break;
        case GAME_STATE_PLAYING:
            level_render();
            break;
        case GAME_STATE_EXIT:
            // Optionally handle rendering for exit state if needed
            break;
    }

    SDL_RenderPresent(renderer);
}
