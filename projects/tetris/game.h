#pragma once

#include <raylib.h>
#include <stdbool.h>

#include "block.h"
#include "grid.h"

typedef struct game_type *Game;

Game create_game(void);
void destroy_game(Game game);
void game_draw(Game game);
void game_handle_input(Game game);
void game_move_block_down(Game game);

// Getters to refer game over or scores from external
bool game_is_over(Game game);
int game_get_score(Game game);
Music game_get_music(Game game);
