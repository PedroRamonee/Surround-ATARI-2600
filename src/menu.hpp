
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
    Font fonte;

   public:
    menu(RenderWindow *window);
    void background(RenderWindow *window);
};

#endif  // MENU_HPP_
