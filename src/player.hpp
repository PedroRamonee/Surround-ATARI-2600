#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "game.hpp"

class PlayerOne : public Snake {
   public:
    PlayerOne(RenderWindow *window, Color cor);
    void changePosition(RenderWindow *window, vector<vector<bool>> grid,
                        bool *end, int *pointer);
    void changeColor(RenderWindow *window, PlayerOne *cobra, int i, int x[],
                     int y[], int counter, int pointer1, int pointer2);
};

class PlayerTwo : public Snake {
   public:
    PlayerTwo(RenderWindow *window, Color cor);
    void changePosition(RenderWindow *window, vector<vector<bool>> grid,
                        bool *end, int *pointer);
    void changeColor(RenderWindow *window, PlayerTwo *cobra2, int i, int x[],
                     int y[], int counter, int pointer1, int pointer2);
};

#endif