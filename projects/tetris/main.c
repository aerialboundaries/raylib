#include <raylib.h>

#include "colors.h"
#include "grid.h"

int main(void)
{
  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Grid gameGrid = create();
  initialize(gameGrid);
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
