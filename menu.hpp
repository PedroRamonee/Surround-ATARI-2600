#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class menu{
    private:
    
    Image icon;
    Image background;
    float positionx=0;
    float positiony=0;
    Music start;
    Music music;
    Font fonte;

    public:
    menu(RenderWindow *window){

        /*
     Construtor do Objeto Menu(-)

     - Configura a posição x e y inicial
     - Carrega imagens de background/icone
     - Carrega arquivos de música de music/start
     - Carrega a fonte

     */
    this->icon = icon.loadFromFile("assets/icone.png");

    this->background = background.loadFromFile("assets/background.jpg");

    this->positionx = window->getSize().x;
    this->positiony = window->getSize().y;

    this->start = start.openFromFile("assets/startdojogo.wav");

    this->music = music.openFromFile("assets/menumusic.wav");

    this->fonte = fonte.loadFromFile("assets/design.graffiti.comicsansmsgras.ttf");
    }
};



#endif /* MENU_HPP_ */
