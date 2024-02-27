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
  void normalise(Vector2& vec);
protected:
  float speed = 2.0;
  Vector2 position = {50, 50};
  Texture2D sprite;
  Rectangle frameRec;
  int currentFrameX = 0;
  int currentFrameY = 0;
};
