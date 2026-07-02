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

// internal functions (prototypes)
static void refill_blocks(Game game);
static int get_random_block_id(Game game);

// internal functions (implementations)
static void refill_blocks(Game game)
{
  for (int i = 0; i < 7; i++) {
    game->remaining_blocks[i] = i + 1; // L_block(1) to Z_block(7)
  }
  game->block_count = 7;
}

static int get_random_block_id(Game game)
{
  if (game->block_count == 0) {
    refill_blocks(game);
  }

  int randomIndex = rand() % game->block_count;
  int blockId = game->remaining_blocks[randomIndex];

  // delete selected item from array and shift the last item
  for (int i = randomIndex; i < game->block_count - 1; i++) {
    game->remaining_blocks[i] = game->remaining_blocks[i + 1];
  }
  game->block_count--;

  return blockId;
}
