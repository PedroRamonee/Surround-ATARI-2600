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

     - Configura a posição x e y inicial
     - Define os controles 
     - Define as constantes boltx e bolty( tamanho da janela divido por 20)
     - Define a origem da cobra e do seu rastro
     - Define o tamanho da cobra e do seu rastro
     - Define a cor da cobra e da marca
     - Inicializa o mapa (false em todas as posiçoes)

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
    mark.setFillColor(Color(150, 0, 255));

    // Inicialização da matriz de 20/20

    for (unsigned int y = 0; y < 20; y++) {
      vector<bool> yAxis;

      for (unsigned int x = 0; x < 20; x++) {
        yAxis.push_back(false);
      }
      this->grid.push_back(yAxis);
    }
  }

  void render(RenderWindow *window);

  void setMark();

  void changePosition(RenderWindow *window);
};


#endif /* GAME_HPP_ */
