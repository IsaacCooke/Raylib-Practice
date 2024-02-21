#include "player.h"

Vector2 Player::getNewPosition(Vector2 ballPosition){
    if(IsKeyDown(KEY_D)) ballPosition.x += 2.0f;
    if(IsKeyDown(KEY_A)) ballPosition.x -= 2.0f;
    if(IsKeyDown(KEY_S)) ballPosition.y += 2.0f;
    if(IsKeyDown(KEY_W)) ballPosition.y -= 2.0f;
  return ballPosition;
}
