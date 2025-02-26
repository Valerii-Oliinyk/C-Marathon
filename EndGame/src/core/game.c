#include "../../inc/core/game.h"
#include "../../inc/core/window.h"
#include "../../inc/core/input.h"
#include "../../inc/core/render.h"
#include "../../inc/menu/menu.h"
#include "../../inc/levels/level.h"

GameState game_state = GAME_STATE_MENU;
int key_states[SDL_NUM_SCANCODES] = {0};  // Add this line

int game_init() {
    if (!initialize_window()) {
        return FALSE;
    }
    return TRUE;
}

void game_update() {
    switch (game_state) {
        case GAME_STATE_MENU:
            menu_update();
            break;
        case GAME_STATE_PLAYING:
            level_update();
            break;
        case GAME_STATE_EXIT:
            game_is_running = FALSE;
            break;
    }
}

void game_render() {
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
}

void game_cleanup() {
    destroy_window();
}
