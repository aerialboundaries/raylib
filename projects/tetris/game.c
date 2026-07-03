#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "block.h"
#include "blocks.h"
#include "colors.h"
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
  Block currentBlock;
  Block nextBlock;
  bool gameOver;
  int score;
  Music music;
  Sound rorateSound;
  Sound clearSound;
};

// internal functions (prototypes)
static void refill_blocks(Game game);
static int get_random_block_id(Game game);
static void game_move_left(Game game);
static void game_move_right(Game game);
static bool is_block_outside(Game game);
static void rotate_block(Game game);
static void lock_block(Game game);
static bool block_fits(Game game);
static void game_reset(Game game);
static void update_score(Game game, int linsCleared, int movoDownPoints);

Game create_game(void)
{
  Game game = malloc(sizeof(struct game_type));
  if (game == NULL)
    terminate("Error: game could not be created.");

  game->grid = create_grid();
  initialize_grid(game->grid);

  game->block_count = 0;
  refill_blocks(game);

  game->currntBlock = create_block(get_random_block_id(game));
  game->nextBlock = create_block(get_random_block_id(game)) return game;
}

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
