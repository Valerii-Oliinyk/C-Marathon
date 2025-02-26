#include <SDL2/SDL.h>

int last_frame_time = 0;

void update() {
    //float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

    last_frame_time = SDL_GetTicks();
}
