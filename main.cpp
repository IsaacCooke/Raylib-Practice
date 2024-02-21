#include <raylib.h>
#include <iostream>

int main(){
  const int screenHeight = 400;
  const int screenWidth = 800;

  InitWindow(screenWidth, screenHeight, "Raylib Test");

  Vector2 ballPosition = {(float)screenWidth/2, (float){screenHeight}/2};

  SetTargetFPS(60);

  while(!WindowShouldClose()){
    if(IsKeyDown(KEY_RIGHT || KEY_D)) ballPosition.x += 2.0f;
    if(IsKeyDown(KEY_LEFT || KEY_A)) ballPosition.x -= 2.0f;
    if(IsKeyDown(KEY_DOWN || KEY_S)) ballPosition.y += 2.0f;
    if(IsKeyDown(KEY_UP || KEY_W)) ballPosition.y -= 2.0f;

    BeginDrawing();

    ClearBackground(WHITE);

    DrawCircleV(ballPosition, 50, RED);

    EndDrawing();

    std::cout << "Frame Running";
  }

  CloseWindow();

  return 0;
}
