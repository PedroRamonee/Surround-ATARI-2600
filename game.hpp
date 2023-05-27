/*
 * game.hpp
 *
 *  Created on: 26 de mai. de 2023
 *      Author: joaoc
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

RectangleShape criaRetangulo(int x, int y, int width, int height);

class Snake {
 private:
  int velx = 0, vely = 0;
  RectangleShape square;
  RectangleShape mark;
  int posx = 0, posy = 0;
  int arrayPosX = 0, arrayPosY = 0;
  int boltx;
  int bolty;
  vector<vector<bool>> grid;

 public:
  Snake(RenderWindow *window, Color cor) {
    /*
     Construtor do Objeto Snake(cobra)

     - Configura a posição inicial
     - Define o tamanho do Quadrado
     - Define a cor da cobra
     - Define a origem da cobra
     - Define o quadrado na posição inicial
     - Seta o mapa



     */
    posx = window->getSize().x / 3;
    posy = window->getSize().y / 3;

    square.setOrigin(100 / 2, 100 / 2);
    square.setPosition(posx, posy);

    mark.setOrigin(100 / 2, 100 / 2);
    mark.setPosition(posx, posy);

    boltx = (window->getSize().x / 20);
    bolty = (window->getSize().y / 20);

    square = criaRetangulo(10, 10, boltx, bolty);
    mark = criaRetangulo(10, 10, boltx, bolty);

    square.setFillColor(cor);
    mark.setFillColor(Color(255, 100, 100));

    // Definicao matriz

    for (unsigned int y = 0; y < 20; y++) {
      vector<bool> yAxis;

      for (unsigned int x = 0; x < 20; x++) {
        yAxis.push_back(false);
      }
      this->grid.push_back(yAxis);
    }
  }

  void render(RenderWindow *window) {
    /*
     Retorna void

     - Desenha o quadrado na tela
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

  void setMark() {
    arrayPosX = posx / boltx;
    arrayPosY = posy / bolty;

    grid[arrayPosX][arrayPosY] = true;
  }

  void changePosition(RenderWindow *window) {
    /*
     Retorna void

     - Altera o valor da posição X e Y
     - Caso as posições sejam maiores que o tamanho da tela ou menores de que 0 a velocidade inverte
     - Caso seja pressionado os botões cima, baixo, direita ou esquerda as velocidades se alteram

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
};

RectangleShape criaRetangulo(int x, int y, int width, int height) {
  RectangleShape rectangle(sf::Vector2f(width, height));

  rectangle.setFillColor(sf::Color::Transparent);

  rectangle.setOutlineColor(sf::Color::White);

  rectangle.setOutlineThickness(1.0f);

  rectangle.setPosition(x, y);

  return rectangle;
}

#endif /* GAME_HPP_ */
