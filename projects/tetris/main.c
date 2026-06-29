#include <raylib.h>

#include "block.h"
#include "blocks.h"
#include "colors.h"
#include "grid.h"

int main(void)
{
  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Grid gameGrid = create_grid();
  initialize_grid(gameGrid);
  printgrid(gameGrid);

  Block currentBlock = create_block(T_BLOCK);
  Move(currentBlock, 4, 3);

  // main loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(colors[darkBlue]);
    Draw(gameGrid);
    draw_block(currentBlock);

    EndDrawing();
  }

  destroy_block(currentBlock);
  destroy_grid(gameGrid);
  CloseWindow();

  return 0;
}
