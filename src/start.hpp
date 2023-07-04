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
    int pointer1 = 0;
    int pointer2 = 0;
    int x[10];
    int y[10];
    int counter = 1;

   public:
    Start();
    ~Start();
    void Update(PlayerOne *cobra, PlayerTwo *cobra2, RenderWindow *window);
    void Draw(PlayerOne *cobra, PlayerTwo *cobra2, RenderWindow *window);
    void runGame(RenderWindow *window);
    void changeCor(RenderWindow *window, PlayerOne *cobra, PlayerTwo *cobra2);
    void gridReset(PlayerOne *cobra, PlayerTwo *cobra2);
    void positionReset(RenderWindow *window, PlayerOne *cobra,
                       PlayerTwo *cobra2);
    void setPedra(PlayerOne *cobra, PlayerTwo *cobra2);
    void setSpeed(PlayerOne *cobra, PlayerTwo *cobra2);
};

#endif