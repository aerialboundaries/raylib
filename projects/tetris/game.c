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
  Sound rotateSound;
  Sound clearSound;
};

// internal functions (prototypes)
static void refill_blocks(Game game);
static int get_random_block_id(Game game);
static void game_move_block_left(Game game);
static void game_move_block_right(Game game);
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

  game->currentBlock = create_block(get_random_block_id(game));
  game->nextBlock = create_block(get_random_block_id(game));

  game->gameOver = false;
  game->score = 0;

  return game;
}

void destroy_game(Game game)
{
  if (game == NULL)
    return;

  destroy_grid(game->grid);
  if (game->currentBlock)
    destroy_block(game->currentBlock);
  if (game->nextBlock)
    destroy_block(game->nextBlock);

  free(game);
}

void game_draw(Game game)
{
  Draw(game->grid);
  draw_block(game->currentBlock);
}

void game_handle_input(Game game)
{
  int keyPressed = GetKeyPressed();
  if (game->gameOver && keyPressed != 0) {
    game->gameOver = false;
    game_reset(game);
  }

  switch (keyPressed) {
  case KEY_LEFT:
    game_move_block_left(game);
    break;
  case KEY_RIGHT:
    game_move_block_right(game);
    break;
  case KEY_DOWN:
    game_move_block_down(game);
    update_score(game, 0, 1);
    break;
  case KEY_UP:
    rotate_block(game);
    break;
  }
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

static void game_move_block_left(Game game)
{
  if (!game->gameOver) {
    Move(game->currentBlock, 0, -1);
    if (is_block_outside(game) || !block_fits(game)) {
      Move(game->currentBlock, 0, 1);
    }
  }
}

static void game_move_block_right(Game game)
{
  if (!game->gameOver) {
    Move(game->currentBlock, 0, 1);
    if (is_block_outside(game) || !block_fits(game)) {
      Move(game->currentBlock, 0, -1);
    }
  }
}

void game_move_block_down(Game game)
{
  if (!game->gameOver) {
    Move(game->currentBlock, 1, 0);
    if (is_block_outside(game) || !block_fits(game)) {
      Move(game->currentBlock, -1, 0);
    }
  }
}

static bool is_block_outside(Game game)
{
  Position tiles[4];
  GetCellPositions(game->currentBlock, tiles);
  for (int i = 0; i < 4; i++) {
    // grid.h に定義されているNUMROWS, NUMCOLSの範囲外かどうかを判定
    if (tiles[i].row < 0 || tiles[i].row >= NUMROWS || tiles[i].column < 0 ||
        tiles[i].column >= NUMCOLS) {
      return true;
    }
  }
  return false;
}

static void rotate_block(Game game)
{
  if (!game->gameOver) {
    rotate_block_state(game->currentBlock);

    if (is_block_outside(game) || !block_fits(game)) {
      // 元に戻す処理
      undo_block_rotation(game->currentBlock);
    } else {
      // PlaySound(game->rotateSound);
    }
  }
}

static void lock_block(Game game)
{
  Position tiles[4];
  GetCellPositions(game->currentBlock, tiles);

  // ブロックをグリッドに固定
  for (int i = 0; i < 4; i++) {
    // block.c から id を取得するゲッター、または直接アクセスが必要です
    // ここでは便宜上、C++のロジック通りにグリッドへ値をセットする流れを示しています
    // ※grid.cのset_cell_value関数を利用します
    // set_cell_value(game->grid, tiles[i].row, tiles[i].column, id);
  }

  destroy_block(game->currentBlock);
  game->currentBlock = game->nextBlock;

  if (!block_fits(game)) {
    game->gameOver = true;
  }

  game->nextBlock = create_block(get_random_block_id(game));

  // グリッドの行削除処理（現状のgrid.cには未実装のため、今後追加する要素となります）
  int rowsCleared = 0;
  if (rowsCleared > 0) {
    PlaySound(game->clearSound);
    update_score(game, rowsCleared, 0);
  }
}

static bool block_fits(Game game)
{
  Position tiles[4];
  GetCellPositions(game->currentBlock, tiles);
  for (int i = 0; i < 4; i++) {
    // グリッド上の該当セルが空(0)かどうかをチェックする処理
    // 必要に応じてgrid.cにセルの値を取得する関数を追加してください
  }
  return true;
}

static void game_reset(Game game)
{
  initialize_grid(game->grid);
  game->block_count = 0;
  refill_blocks(game);

  if (game->currentBlock)
    destroy_block(game->currentBlock);
  if (game->nextBlock)
    destroy_block(game->nextBlock);

  game->currentBlock = create_block(get_random_block_id(game));
  game->nextBlock = create_block(get_random_block_id(game));
  game->score = 0;
}

static void update_score(Game game, int linesCleared, int moveDownPoints)
{
  switch (linesCleared) {
  case 1:
    game->score += 100;
    break;
  case 2:
    game->score += 300;
    break;
  case 3:
    game->score += 500;
    break;
  default:
    break;
  }
  game->score += moveDownPoints;
}

bool game_is_over(Game game)
{
  return game->gameOver;
}

int game_get_score(Game game)
{
  return game->score;
}

Music game_get_music(Game game)
{
  return game->music;
}
