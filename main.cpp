#include <raylib.h>

#include "src/player.h"

int main(){
  const int screenHeight = 400;
  const int screenWidth = 800;

  InitWindow(screenWidth, screenHeight, "Raylib Test");

  Player player;

  SetTargetFPS(60);

  while(!WindowShouldClose()){
    // Update
    player.updatePlayer(player);

    // Draw
    BeginDrawing();

    ClearBackground(WHITE);

    player.drawPlayer(player);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
