#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "colors.h"
#include "game.h"

int main(void)
{
  srand((unsigned int)time(NULL));

  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Game game = create_game();

  // main loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(colors[darkBlue]);

    game_draw(game);

    EndDrawing();
  }

  destroy_game(game);
  CloseWindow();

  return 0;
}
