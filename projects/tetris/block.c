#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "block.h"
#include "blocks.h"
#include "colors.h"
#include "position.h"

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

struct block_type {
  int id;
  int cellSize;
  int rotationState;
  Position offset;
  Color colors[MAX_COLOR];
};

Block create_block(int id)
{
  Block b = malloc(sizeof(struct block_type));
  if (b == NULL)
    terminate("Error in create: block could not be created.");

  b->id = id;
  b->cellSize = 30;
  b->rotationState = 0;
  b->offset.row = 0;    // start from top of screen
  b->offset.column = 3; // start from middle of screen
                        //
  memcpy(b->colors, colors, sizeof(colors));

  return b;
}

void destroy_block(Block b)
{
  free(b);
}

/* ブロックを画面に描画する関数を追加しました */
void draw_block(Block b)
{
  /* blocks.c で定義されている配列から、現在の回転状態の4つのセルの座標を取得 */
  for (int i = 0; i < 4; i++) {
    Position cell_pos = block_shapes[b->id][b->rotationState][i];

    /* 基準位置（offset）にセルの相対座標を足して、実際の画面上の位置を計算 */
    int screen_row = b->offset.row + cell_pos.row;
    int screen_col = b->offset.column + cell_pos.column;

    DrawRectangle(screen_col * b->cellSize + 1, screen_row * b->cellSize + 1,
                  b->cellSize - 1, b->cellSize - 1, b->colors[b->id]);
  }
}
