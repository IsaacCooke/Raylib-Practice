#include <raylib.h>

#include "src/player.h"

int main(){
  const int screenHeight = 400;
  const int screenWidth = 800;

  InitWindow(screenWidth, screenHeight, "Raylib Test");

  Vector2 ballPosition = {(float)screenWidth/2, (float){screenHeight}/2};

  SetTargetFPS(60);

  Player player = Player();

  while(!WindowShouldClose()){

    BeginDrawing();

    ClearBackground(WHITE);

    DrawCircleV(player.getNewPosition(ballPosition), 50, RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
