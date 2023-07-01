#ifndef START_HPP_
#define START_HPP_

#include "game.hpp"
#include "menu.hpp"
#include "player.hpp"

class Start {
   private:
    RenderWindow window;
    int controller = 0;

   public:
    Start();
    ~Start();
    void Update(PlayerOne *cobra, PlayerTwo *cobra2);
    void Draw(PlayerOne *cobra, PlayerTwo *cobra2);
    void Verify(PlayerOne *cobra, PlayerTwo *cobra2);
    void runGame();
};

#endif