#include "player.hpp"

void PlayerOne::changePosition(RenderWindow *window) {
    /*
     Retorna void

     - Altera o valor da posição X e Y
     - Caso as posições sejam maiores que o tamanho da tela ou menores iguais a 0 a posição se altera 
     - Caso seja pressionado os botões cima, baixo, direita ou esquerda as velocidades se alteram
     - Define a posição nova do quadrado

     */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      vely = 0;
      velx = -2;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      vely = 0;
      velx = 2;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      vely = -2;
      velx = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      vely = 2;
      velx = 0;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      vely = 0;
      velx = 0;
    }

    posx = posx + velx;
    posy = posy + vely;

    if (posx >= window->getSize().x) {
      posx = window->getSize().x - 1;
    }
    if (posx <= 0) {
      posx = 0;
    }
    if (posy >= window->getSize().y) {
      posy = window->getSize().y - 1;
    }
    if (posy <= 0) {
      posy = 0;
    }

    setMark();
    square.setPosition(arrayPosX * boltx, arrayPosY * bolty);
 }

void PlayerTwo::changePosition(RenderWindow *window) {
    /*
     Retorna void

     - Altera o valor da posição X e Y
     - Caso as posições sejam maiores que o tamanho da tela ou menores iguais a 0 a posição se altera 
     - Caso seja pressionado os botões cima, baixo, direita ou esquerda as velocidades se alteram
     - Define a posição nova do quadrado

     */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      vely = 0;
      velx = -2;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      vely = 0;
      velx = 2;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      vely = -2;
      velx = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      vely = 2;
      velx = 0;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      vely = 0;
      velx = 0;
    }

    posx = posx + velx;
    posy = posy + vely;

    if (posx >= window->getSize().x) {
      posx = window->getSize().x - 1;
    }
    if (posx <= 0) {
      posx = 0;
    }
    if (posy >= window->getSize().y) {
      posy = window->getSize().y - 1;
    }
    if (posy <= 0) {
      posy = 0;
    }

    setMark();
    square.setPosition(arrayPosX * boltx, arrayPosY * bolty);
 }