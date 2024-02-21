#include <raylib.h>

int main(){
  const int screenHeight = 400;
  const int screenWidth = 800;

  InitWindow(screenWidth, screenHeight, "Raylib Test");

  SetTargetFPS(60);

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText("Window Created", 190, 200, 20, GREEN);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
