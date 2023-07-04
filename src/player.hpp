#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "game.hpp"

class PlayerOne : public Snake {
   public:
    PlayerOne(RenderWindow *window, Color cor);
    void changePosition(RenderWindow *window, vector<vector<bool>> grid,
                        bool *end);
};

class PlayerTwo : public Snake {
   public:
    PlayerTwo(RenderWindow *window, Color cor);
    void changePosition(RenderWindow *window, vector<vector<bool>> grid,
                        bool *end);
};

#endif