#include <raylib.h>
#include <string>

using namespace std;

class Player {
public:
  void setupPlayer();
  void updatePlayer();
  void drawPlayer();
  void unloadPlayer();
protected:
  float speed = 0.5;
  Vector2 position = {50, 50};
  Texture2D sprite;
};
