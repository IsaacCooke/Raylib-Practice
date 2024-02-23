#include <raylib.h>

#include "src/player.h"

int main(){
  const int screenHeight = 400;
  const int screenWidth = 800;

  InitWindow(screenWidth, screenHeight, "Raylib Test");

  Player player;
  player.setupPlayer();

  SetTargetFPS(60);

  while(!WindowShouldClose()){
    // Update
    player.updatePlayer();

    // Draw
    BeginDrawing();

    ClearBackground(WHITE);

    player.drawPlayer();

    EndDrawing();
  }

  player.unloadPlayer();

  CloseWindow();

  return 0;
}
