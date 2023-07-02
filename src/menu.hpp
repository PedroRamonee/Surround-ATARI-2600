
#ifndef MENU_HPP_
#define MENU_HPP_

#include "start.hpp"

class menu {
   private:
    Image icon;
    Texture backgroundd;
    float positionx = 0;
    float positiony = 0;
    Music start;
    Music music;
    Music inicio;
    Texture marca;
    RectangleShape botao[3];
    int count = 0;
    Clock relogio;
    Texture credito;
    Texture number[5];
    Music tema;
    float altura;

   public:
    menu(RenderWindow *window);
    void background(RenderWindow *window);
    void botaum(RenderWindow *window,int *control);
    void creditos(RenderWindow *window, int *control);
};

#endif  // MENU_HPP_
