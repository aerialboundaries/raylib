#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "grid.h"

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

struct game_type {
  Grid grid;
  int remaining_blocks[7]; // array to store remaining block id
  int block_count;         // number of remaining blocks
};

Game create_game(void)
{
  Game game = malloc(sizeof(struct game_type));
  if (game == NULL)
    terminate("Error: game could not be created.");

  game->grid = create_grid();
  initialize_grid(game->grid);

  return game;
}
