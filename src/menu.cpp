#include "menu.hpp"
menu::menu(RenderWindow *window) {
    /* Construtor do Objeto Menu(-)

     - Configura a posição x e y inicial
     - Carrega imagens de background/icone
     - Carrega arquivos de música de music/start
     - Carrega a fonte*/

    this->icon.loadFromFile("assets/icone.png");

    this->backgroundd.loadFromFile("assets/background.jpg");

    this->positionx = window->getSize().x;
    this->positiony = window->getSize().y;

    this->start.openFromFile("assets/startdojogo.wav");

    this->music.openFromFile("assets/menumusic.wav");

    this->fonte.loadFromFile("assets/design.graffiti.comicsansmsgras.ttf");
}
void menu::background(RenderWindow *window) {
    Sprite sprite;
    sprite.setTexture(backgroundd);
    window->draw(sprite);
}
