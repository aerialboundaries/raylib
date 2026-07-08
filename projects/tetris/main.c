#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "colors.h"
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main(void)
{
  srand((unsigned int)time(NULL));

  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Game game = create_game();

  // main loop
  while (!WindowShouldClose()) {
    game_handle_input(game);
    if (EventTriggered(0.2)) {
      game_move_block_down(game);
    }
    BeginDrawing();
    ClearBackground(colors[darkBlue]);

    game_draw(game);

    EndDrawing();
  }

  destroy_game(game);
  CloseWindow();

  return 0;
}
