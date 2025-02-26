#ifndef LEVEL_H
#define LEVEL_H

#include "../player/player.h"
#include "../core/constants.h"
#include "math.h"

#define NUM_BLOCKS 5
#define NUM_TRIANGLES 3

void level_update();
void level_render();

typedef struct {
    SDL_Rect rect;
} Block;

typedef struct {
    SDL_Point points[3];
} Triangle;

typedef struct Level {
    Block blocks[NUM_BLOCKS];
    Triangle triangles[NUM_TRIANGLES];
} Level;

void init_level(Level *level);
void load_level(Level *level, const char *filename); 
void draw_level(Level *level, SDL_Renderer *renderer);
int check_collision_y(Player *player, Level *level);
int check_collision_x(Player *player, Level *level);
int check_collision_with_triangles(Player *player, Level *level);

#endif
