#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "../core/constants.h"

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 50

#define PLAYER_SPEED 5.0f
#define PLAYER_JUMP_STRENGTH -20.0f
#define PLAYER_GRAVITY 1.5f
#define PLAYER_MAX_FALL_SPEED 20.0f

typedef struct {
    SDL_Rect rect;
    float velX, velY;
    SDL_Texture *texture; 
    SDL_Rect srcRect; 
    int currentFrame; 
    int onGround; 
    SDL_Texture *idleTexture; 
    SDL_Texture *runTexture; 
    SDL_Texture *jumpTexture; 
    int idleSpriteCount; 
    int runSpriteCount;
    Uint32 animationSpeed;
    Uint32 lastFrameUpdate;
} Player;

typedef struct Level Level;

void init_player(Player *player, int x, int y, SDL_Renderer *renderer); 
void update_player(Player *player, Level *level); 
void handle_player_input(Player *player, SDL_Event *event); 
void load_player_textures(Player *player, SDL_Renderer *renderer); 
void destroy_player_textures(Player *player); 

#endif

