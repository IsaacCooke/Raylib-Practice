#include "player.h"

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

  position.x += positionDelta.x * speed;
  position.y += positionDelta.y * speed;

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
  
}

void Player::drawPlayer(){
  DrawTextureRec(Player::sprite, Player::frameRec, Player::position, WHITE);
}

void Player::unloadPlayer(){
  UnloadTexture(Player::sprite);
}
