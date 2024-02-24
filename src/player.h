#include <raylib.h>
#include <string>

#include "animation.h"

using namespace std;

class Player {
public:
  void setupPlayer();
  void updatePlayer();
  void drawPlayer();
  void unloadPlayer();

  void getNextFrame(AnimationType animationType);
protected:
  float speed = 0.5;
  Vector2 position = {50, 50};
  Texture2D sprite;
  Rectangle frameRec;
  int currentFrameX = 0;
  int currentFrameY = 0;
};
