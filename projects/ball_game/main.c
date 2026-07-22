#include <raylib.h>

int main()
{
  int ballX = 400;
  int ballY = 400;
  Color green = {20, 100, 133, 255};

  InitWindow(800, 800, "My first raylib Game");
  SetTargetFPS(60);

  // game loop
  while (!WindowShouldClose()) {
    // 1. Event Handling
    if (IsKeyDown(KEY_RIGHT)) {
      ballX += 3;
    } else if (IsKeyDown(KEY_LEFT)) {
      ballX -= 3;
    } else if (IsKeyDown(KEY_UP)) {
      ballY -= 3;
    } else if (IsKeyDown(KEY_DOWN)) {
      ballY += 3;
    }

    // 2. Updating Positions
    // 3. Dwawing
    BeginDrawing();
    ClearBackground(green);
    DrawCircle(ballX, ballY, 20, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
