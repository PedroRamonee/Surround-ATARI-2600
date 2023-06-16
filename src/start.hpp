#ifndef START_HPP_
#define START_HPP_

#include "game.hpp"
#include "player.hpp"


class Start{

private:
    PlayerOne *cobra;
    PlayerTwo *cobra2;
    RenderWindow window;

public:

    Start();
    ~Start();
    void Restart();
    void Update();
    void Draw();
    void runGame();
};

#endif