#include "../inc/core/game.h"
#include "../inc/core/input.h"
#include "../inc/player/player.h"

int game_is_running = TRUE;
Player player;

int main() {
    if (!game_init()) {
        fprintf(stderr, "Failed to initialize game.\n");
        return -1;
    }

    printf("Game initialized successfully.\n");

    SDL_Event event;
    while (game_is_running) {
        process_input(&player, &event);
        game_update();
        game_render();
    }

    game_cleanup();

    return 0;
}
