#include <raylib.h>

#include "colors.h"
#include "grid.h"

int main(void)
{
  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Grid gameGrid = create();
  initialize(gameGrid);
  set_cell_value(gameGrid, 0, 0, 1);
  set_cell_value(gameGrid, 3, 5, 4);
  set_cell_value(gameGrid, 17, 8, 7);

  printgrid(gameGrid);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(colors[darkBlue]);
    Draw(gameGrid);

    EndDrawing();
  }

  destroy(gameGrid);
  CloseWindow();

  return 0;
}
