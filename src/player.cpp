#include "player.h"
#include <cmath>
#include <iostream>
#include <raylib.h>
#include <math.h>

int framesCounter = 0;
int framesSpeed = 8;

void Player::setupPlayer(){
  sprite = LoadTexture("../assets/AnimationSheet.png");

  frameRec = {
    0.0f,
    0.0f,
    (float)sprite.width/8,
    (float)sprite.height/6
  };
}

void Player::updatePlayer(){
  // Position
  Vector2 positionDelta = {0, 0};

  if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_THUMB)){
    positionDelta.x += (int)GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);
    positionDelta.y += ((int)1 + GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y));
  }
  else {
    if(IsKeyDown(KEY_D)) positionDelta.x += 2.0f;
    if(IsKeyDown(KEY_A)) positionDelta.x -= 2.0f;
    if(IsKeyDown(KEY_S)) positionDelta.y += 2.0f;
    if(IsKeyDown(KEY_W)) positionDelta.y -= 2.0f;
  }

  normalise(positionDelta);

  if (!isnan(positionDelta.x)){
    position.x += positionDelta.x * speed;
  }
  if (!isnan(positionDelta.y)){
    position.y += positionDelta.y * speed;
  }

  // Animation
  framesCounter++;
  if(framesCounter >= (60/framesSpeed)){
    framesCounter = 0;
    Player::currentFrameX++;

    if (Player::currentFrameX > 8) currentFrameX = 0;

    frameRec.x = (float)currentFrameX*(float)sprite.width/8;
    frameRec.y = /*(float)currentFrameX**/(float)sprite.width/6;
  }
}

void Player::getNextFrame(AnimationType animationType){
  // std::vector<int> frameIndices;
  // switch (animationType) {
  //   case AnimationType::idle:
  //     frameIndices = [1, 10];
  //   case AnimationType::walk:
  //     frameIndices = [11, 20];
  //   default:
  //     throw std::cerr("Animation not found");
  //     break;
  // }
}

void Player::drawPlayer(){
  DrawTextureRec(Player::sprite, Player::frameRec, Player::position, WHITE);
}

void Player::unloadPlayer(){
  UnloadTexture(Player::sprite);
}

void Player::normalise(Vector2& vec){
  float& x = vec.x;
  float& y = vec.y;
  float mod = sqrt(x * x + y * y);

  x = x / mod;
  y = y / mod;
}
