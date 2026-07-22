#include <raylib.h>

int main()
{
  InitWindow(800, 800, "My first raylib Game");

  // game loop
  while (!WindowShouldClose()) {
    // 1. Event Handling
    // 2. Updating Positions
    // 3. Dwawing
    BeginDrawing();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
