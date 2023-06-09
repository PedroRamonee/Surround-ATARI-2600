#include "game.hpp"

class PlayerOne : public Snake {

public:

      PlayerOne(RenderWindow *window, Color cor);
      void changePosition(RenderWindow *window);

};

class PlayerTwo : public Snake {

public:

      PlayerTwo(RenderWindow *window, Color cor);
      void changePosition(RenderWindow *window);

};