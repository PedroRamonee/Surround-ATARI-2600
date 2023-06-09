#include "game.hpp"

class PlayerOne : public Snake {

    public:

         PlayerOne(RenderWindow *window, Color cor) {
    /*
     Construtor do Objeto 

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
    mark.setFillColor(Color::Blue);

    // Inicialização da matriz de 20/20

    for (unsigned int y = 0; y < 20; y++) {
      vector<bool> yAxis;

      for (unsigned int x = 0; x < 20; x++) {
        yAxis.push_back (false);
      }
      this->grid.push_back(yAxis);
    }
  }


         void changePosition(RenderWindow *window);

};

class PlayerTwo : public Snake {

    public:
    PlayerTwo(RenderWindow *window, Color cor) {
    /*
     Construtor do Objeto 

     - Configura a posição x e y inicial
     - Define os controles 
     - Define as constantes boltx e bolty( tamanho da janela divido por 20)
     - Define a origem da cobra e do seu rastro
     - Define o tamanho da cobra e do seu rastro
     - Define a cor da cobra e da marca
     - Inicializa o mapa (false em todas as posiçoes)

     */


    posx = window->getSize().x / 6;
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
    mark.setFillColor(Color::Red);

    // Inicialização da matriz de 20/20

    for (unsigned int y = 0; y < 20; y++) {
      vector<bool> yAxis;

      for (unsigned int x = 0; x < 20; x++) {
        yAxis.push_back (false);
      }
      this->grid.push_back(yAxis);
    }
  }

         void changePosition(RenderWindow *window);

};