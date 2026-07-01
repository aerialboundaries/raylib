#pragma once

#include "block.h"
#include "grid.h"

typedef struct game_type *Game;

Game create_game(void);
void destroy_game(Game game);
