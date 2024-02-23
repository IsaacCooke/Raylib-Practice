#include "player.h"
#include <iostream>
#include <raylib.h>

void Player::setupPlayer(){
  Player::sprite = LoadTexture("../assets/AnimationSheet.png");
}

void Player::updatePlayer(){
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

  Player::position.x += positionDelta.x * Player::speed;
  Player::position.y += positionDelta.y * Player::speed;
}

void Player::drawPlayer(){
  DrawTextureV(Player::sprite, Player::position, WHITE);
}

void Player::unloadPlayer(){
  UnloadTexture(Player::sprite);
}
