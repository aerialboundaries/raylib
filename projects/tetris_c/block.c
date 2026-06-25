#include "block.h"
#include <raylib.h>

struct block_type {
  Vector2 pos;
  int shape[N][N];
  Color color;
};

Block GenerateBlock(Block blocks[NUM_PIECES]);
void DrawBlock(Block b);
void SetBlockPos(Block b);
void MoveRight(Block b);
void MoveLeft(Block b);
void MoveDown(Block b);
void Rotate(Block b);
