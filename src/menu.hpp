
#ifndef MENU_HPP_
#define MENU_HPP_

#include "start.hpp"

class menu {
   private:
    Texture backgroundd;
    float positionx = 0;
    float positiony = 0;
    Music start;
    Music music;
    Music inicio;
    Texture marca[6];
    RectangleShape botao[3];
    int count = 0;
    Clock relogio;
    Texture credito;
    Texture number[5];
    Music tema;
    float altura;
    Texture reinicio;
    RectangleShape botaorestart[2];
    int countRestart = 0;

   public:
    menu(RenderWindow *window);
    void background(RenderWindow *window);
    void botaum(RenderWindow *window, int *control);
    void creditos(RenderWindow *window, int *control);
    void restart(RenderWindow *window);
    void botaumRestart(RenderWindow *window, int *control, bool *reset);
    void pauseTema();
};

#endif  // MENU_HPP_
