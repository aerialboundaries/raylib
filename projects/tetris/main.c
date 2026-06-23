#include <raylib.h>

#include "grid.h"

int main(void)
{
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Grid gameGrid = create();
  initialize(gameGrid);
  printgrid(gameGrid);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(darkBlue);

    EndDrawing();
  }

  destroy(gameGrid);
  CloseWindow();

  return 0;
}
