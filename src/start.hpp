#ifndef START_HPP_
#define START_HPP_

#include "game.hpp"
#include "menu.hpp"
#include "player.hpp"

class Start {
   private:
    int controller = 1;
    bool reset = false;
    bool end = false;
    int count = 0;
    Music reiniciomusica;

   public:
    Start();
    ~Start();
    void Update(PlayerOne *cobra, PlayerTwo *cobra2, RenderWindow *window);
    void Draw(PlayerOne *cobra, PlayerTwo *cobra2, RenderWindow *window);
    void runGame(RenderWindow *window);
    void changeColor(RenderWindow *window, PlayerOne *cobra, PlayerTwo *cobra2);
    void gridReset(PlayerOne *cobra, PlayerTwo *cobra2);
    void positionReset(RenderWindow *window, PlayerOne *cobra,
                       PlayerTwo *cobra2);
};

#endif