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

    setBoard();
    
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

  void Snake :: setBoard(){
    for(int i = 0; i < 20; i++){
      grid[i][0] = true;
      grid[0][i] = true;
      grid[i][19] = true;
      grid[19][i] = true;
    }
  

  }

 RectangleShape criaRetangulo(int x, int y, int width, int height) {
  RectangleShape rectangle(sf::Vector2f(width, height));

  rectangle.setFillColor(sf::Color::Transparent);

  rectangle.setOutlineColor(sf::Color::White);

  rectangle.setOutlineThickness(1.0f);

  rectangle.setPosition(x, y);

  return rectangle;
}


