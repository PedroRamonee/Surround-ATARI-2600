/*
 * game.cpp
 *
 *  Created on: 26 de mai. de 2023
 *      Author: joaoc
 */

#include "game.hpp"


void Snake::render(RenderWindow *window){

    /*
     Retorna void

     - Desenha os quadrados na tela
     */

    
    for (unsigned int y = 0; y < this->grid.size(); y++) {
      for (unsigned int x = 0; x < this->grid[y].size(); x++) {
        if (grid[x][y]) {
          mark.setPosition(Vector2f(boltx * x, bolty * y));

          window->draw(mark);
        }
      }
    }

    window->draw(square);

}

void Snake :: setMark() {

   /*
     Retorna void

     - Encontra a posição na matriz referente a posição na janela
     - Define a posição como true

     */


    arrayPosX = posx / boltx;
    arrayPosY = posy / bolty;

    grid[arrayPosX][arrayPosY] = true;
  }

 void Snake::changePosition(RenderWindow *window) {
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

 RectangleShape criaRetangulo(int x, int y, int width, int height) {
  RectangleShape rectangle(sf::Vector2f(width, height));

  rectangle.setFillColor(sf::Color::Transparent);

  rectangle.setOutlineColor(sf::Color::White);

  rectangle.setOutlineThickness(1.0f);

  rectangle.setPosition(x, y);

  return rectangle;
}


