#include <raylib.h>

class Player {
public:
  Vector2 getNewPosition(Vector2 ballPosition);
  void setupPlayer(Player& player);
  void updatePlayer(Player& player);
  void drawPlayer(Player& player);
protected:
  float speed = 0.5;
  Vector2 position = {50, 50};
};
