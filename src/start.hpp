#ifndef START_HPP_
#define START_HPP_

#include "game.hpp"
#include "player.hpp"
#include "menu.hpp"
   
class Start {
   private:
    RenderWindow window;
    int controller = 1;
    
   public:
    Start();
    ~Start();
    void Update(PlayerOne *cobra, PlayerTwo *cobra2);
    void Draw( PlayerOne*cobra, PlayerTwo *cobra2);
    void runGame();
};

#endif