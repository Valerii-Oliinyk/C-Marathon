#include "../../inc/core/utils.h"
#include <SDL2/SDL_image.h>

SDL_Texture *load_texture(SDL_Renderer *renderer, const char *path) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, path);
    if (!texture) {
        fprintf(stderr, "Failed to load texture: %s\n", IMG_GetError());
    }
    return texture;
}
