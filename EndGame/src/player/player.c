#include "../inc/player/player.h"
#include "../../inc/levels/level.h"
#include "../../inc/core/utils.h"

void init_player(Player *player, int x, int y, SDL_Renderer *renderer) {
    player->rect.x = x;
    player->rect.y = y;
    player->rect.w = PLAYER_WIDTH;
    player->rect.h = PLAYER_HEIGHT;
    player->velX = 0.0f;
    player->velY = 0.0f;
    player->currentFrame = 0;
    player->onGround = 0;

    load_player_textures(player, renderer);
    player->srcRect.x = 0;
    player->srcRect.y = 0;
    player->srcRect.w = 32;
    player->srcRect.h = 32;

    player->idleSpriteCount = 11;
    player->runSpriteCount = 12;
    player->animationSpeed = 100;

    player->lastFrameUpdate = SDL_GetTicks();
}

void update_player(Player *player, Level *level) {
    float gravityMultiplier = (player->velY < 0) ? 0.85f : 1.0f;
    player->velY += PLAYER_GRAVITY * gravityMultiplier;

    if (player->velY > PLAYER_MAX_FALL_SPEED) {
        player->velY = PLAYER_MAX_FALL_SPEED;
    }

    player->rect.y += (int)player->velY;

    if (check_collision_y(player, level)) {
        player->velY = 0;
        player->onGround = 1;
    } else {
        player->onGround = 0;
    }

    player->rect.x += (int)player->velX;

    if (check_collision_x(player, level)) {
        player->velX = 0;
    }

    if (check_collision_with_triangles(player, level)) {
        player->rect.x = START_X;
        player->rect.y = START_Y;
    }

    if (player->rect.x < 0) {
        player->rect.x = 0;
    } else if (player->rect.x > WINDOW_WIDTH - player->rect.w) {
        player->rect.x = WINDOW_WIDTH - player->rect.w;
    }

    if (player->rect.y < 0) {
        player->rect.y = 0;
        player->velY = 0;
    } else if (player->rect.y > WINDOW_HEIGHT - player->rect.h) {
        player->rect.y = WINDOW_HEIGHT - player->rect.h;
        player->velY = 0;
        player->onGround = 1;
    }

    SDL_Texture* nextTexture = player->idleTexture;

    if (player->velX != 0) {
        nextTexture = player->runTexture;
    }

    if (!player->onGround) {
        nextTexture = player->jumpTexture;
    }

    if (player->texture != nextTexture) {
        player->texture = nextTexture;
        player->currentFrame = 0;
    }

    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - player->lastFrameUpdate > player->animationSpeed) {
        player->currentFrame++;

        int frameCount = 0;
        if (player->texture == player->idleTexture) {
            frameCount = player->idleSpriteCount;
        } else if (player->texture == player->runTexture) {
            frameCount = player->runSpriteCount;
        } else if (player->texture == player->jumpTexture) {
            frameCount = 6;
        }

        if (player->currentFrame >= frameCount) {
            player->currentFrame = 0;
        }

        player->lastFrameUpdate = currentTime;

        player->srcRect.x = player->currentFrame * player->srcRect.w;
    }
}

void handle_player_input(Player *player, SDL_Event *event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            case SDLK_LEFT:
                player->velX = -PLAYER_SPEED;
                break;
            case SDLK_RIGHT:
                player->velX = PLAYER_SPEED;
                break;
            case SDLK_SPACE:
                if (player->onGround) {
                    player->velY = PLAYER_JUMP_STRENGTH;
                    player->onGround = 0;
                }
                break;
        }
    } else if (event->type == SDL_KEYUP) {
        switch (event->key.keysym.sym) {
            case SDLK_LEFT:
            case SDLK_RIGHT:
                player->velX = 0;
                break;
        }
    }
}

void load_player_textures(Player *player, SDL_Renderer *renderer) {
    player->idleTexture = load_texture(renderer, "resource/Free/Main Characters/Ninja Frog/Idle (32x32).png");
    player->runTexture = load_texture(renderer, "resource/Free/Main Characters/Ninja Frog/Run (32x32).png");
    player->jumpTexture = load_texture(renderer, "resource/Free/Main Characters/Ninja Frog/Double Jump (32x32).png");

    if (!player->idleTexture || !player->runTexture || !player->jumpTexture) {
        fprintf(stderr, "Error loading player textures!\n");
        exit(1);
    }

    player->texture = player->idleTexture;
}

void destroy_player_textures(Player *player) {
    SDL_DestroyTexture(player->idleTexture);
    SDL_DestroyTexture(player->runTexture);
    SDL_DestroyTexture(player->jumpTexture);
}
