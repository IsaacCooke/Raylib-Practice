#include "player.h"

Vector2 Player::getNewPosition(Vector2 ballPosition){
    if(IsKeyDown(KEY_D)) ballPosition.x += 2.0f;
    if(IsKeyDown(KEY_A)) ballPosition.x -= 2.0f;
    if(IsKeyDown(KEY_S)) ballPosition.y += 2.0f;
    if(IsKeyDown(KEY_W)) ballPosition.y -= 2.0f;
  return ballPosition;
}

void Player::setupPlayer(Player& player){

}

void Player::updatePlayer(Player& player){
  Vector2 positionDelta = {0, 0};
  if(IsKeyDown(KEY_D)) positionDelta.x += 2.0f;
  if(IsKeyDown(KEY_A)) positionDelta.x -= 2.0f;
  if(IsKeyDown(KEY_S)) positionDelta.y += 2.0f;
  if(IsKeyDown(KEY_W)) positionDelta.y -= 2.0f;

  player.position.x += positionDelta.x * player.speed;
  player.position.y += positionDelta.y * player.speed;
}

void Player::drawPlayer(Player& player){
  DrawCircleV(player.position, 50, BLUE);
}
