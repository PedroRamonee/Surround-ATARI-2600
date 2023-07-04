#include "player.hpp"

PlayerOne::PlayerOne(RenderWindow *window, Color cor) {
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
    boltx = (window->getSize().x / 30);
    bolty = (window->getSize().y / 30);

    posx = rand() % (window->getSize().x - 2 * boltx) + boltx;
    posy = rand() % (window->getSize().y - 2 * bolty) + bolty;

    if (posx == window->getSize().x) {
        posx -= boltx;
    }
    if (posy == window->getSize().y) {
        posy -= bolty;
    }

    startPosX = posx;
    startPosY = posy;

    square.setOrigin(100 / 2, 100 / 2);
    square.setPosition(posx, posy);

    mark.setOrigin(100 / 2, 100 / 2);
    mark.setPosition(posx, posy);

    square = criaRetangulo(10, 10, boltx, bolty);
    mark = criaRetangulo(10, 10, boltx, bolty);

    square.setFillColor(cor);
    mark.setFillColor(Color::Blue);

    // Inicialização da matriz de 20/20

    for (unsigned int y = 0; y < 30; y++) {
        vector<bool> yAxis;

        for (unsigned int x = 0; x < 30; x++) {
            yAxis.push_back(false);
        }
        this->grid.push_back(yAxis);
    }
}

PlayerTwo::PlayerTwo(RenderWindow *window, Color cor) {
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

    boltx = (window->getSize().x / 30);
    bolty = (window->getSize().y / 30);

    posx = rand() % (window->getSize().x - 2 * boltx) + boltx;
    posy = rand() % (window->getSize().y - 2 * bolty) + bolty;

    if (posx == window->getSize().x) {
        posx -= boltx;
    }
    if (posy == window->getSize().y) {
        posy -= bolty;
    }

    startPosX = posx;
    startPosY = posy;

    square.setOrigin(100 / 2, 100 / 2);
    square.setPosition(posx, posy);

    mark.setOrigin(100 / 2, 100 / 2);
    mark.setPosition(posx, posy);

    square = criaRetangulo(10, 10, boltx, bolty);
    mark = criaRetangulo(10, 10, boltx, bolty);

    square.setFillColor(cor);
    mark.setFillColor(Color::Red);

    // Inicialização da matriz de 20/20

    for (unsigned int y = 0; y < 30; y++) {
        vector<bool> yAxis;

        for (unsigned int x = 0; x < 30; x++) {
            yAxis.push_back(false);
        }
        this->grid.push_back(yAxis);
    }
}

void PlayerOne::changePosition(RenderWindow *window, vector<vector<bool>> grid,
                               bool *end, int *pointer) {
    /*
     Retorna void

     - Altera o valor da posição X e Y
     - Caso as posições sejam maiores que o tamanho da tela ou menores iguais a
     0 a posição se altera
     - Caso seja pressionado os botões cima, baixo, direita ou esquerda as
     velocidades se alteram
     - Define a posição nova do quadrado

     */

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vely = 0;
        velx = -30;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        vely = 0;
        velx = 30;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        vely = -30;
        velx = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        vely = 30;
        velx = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        vely = 0;
        velx = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window->close();
    }

    if (clock.getElapsedTime().asSeconds() > 0.2) {
        posx += velx;
        posy += vely;

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

        setMark(grid, end, pointer);
        square.setPosition(arrayPosX * boltx, arrayPosY * bolty);

        if (f % 2 == 0) {
            pisk = pisk + 5;
            if (pisk >= 255) {
                f++;
            }
        } else {
            pisk = pisk - 5;
            if (pisk <= 0) {
                f++;
            }
        }

        mark.setFillColor(Color(10, 10, pisk));
        clock.restart();
    }
}

void PlayerTwo::changePosition(RenderWindow *window, vector<vector<bool>> grid,
                               bool *end, int *pointer) {
    /*
     Retorna void

     - Altera o valor da posição X e Y
     - Caso as posições sejam maiores que o tamanho da tela ou menores iguais a
     0 a posição se altera
     - Caso seja pressionado os botões cima, baixo, direita ou esquerda as
     velocidades se alteram
     - Define a posição nova do quadrado

     */

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        vely = 0;
        velx = -30;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        vely = 0;
        velx = 30;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        vely = -30;
        velx = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        vely = 30;
        velx = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        vely = 0;
        velx = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window->close();
    }

    if (clock.getElapsedTime().asSeconds() > 0.2) {
        posx += velx;
        posy += vely;

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

        setMark(grid, end, pointer);
        square.setPosition(arrayPosX * boltx, arrayPosY * bolty);

        if (f % 2 == 0) {
            pisk = pisk + 5;
            if (pisk >= 255) {
                f++;
            }
        } else {
            pisk = pisk - 5;
            if (pisk <= 0) {
                f++;
            }
        }

        mark.setFillColor(Color(pisk, 10, 10));
        clock.restart();
    }
}

void PlayerTwo::changeColor(RenderWindow *window, PlayerTwo *cobra2, int i,
                            int x[], int y[], int counter) {
    if (i % 2 == 0) {
        pisk = 10;
    } else {
        pisk = 255;
    }
    square.setFillColor(Color(pisk, 10, 10));
    mark.setFillColor(Color(pisk, 10, 10));
    cobra2->render(window, x, y, counter);
}

void PlayerOne::changeColor(RenderWindow *window, PlayerOne *cobra, int i,
                            int x[], int y[], int counter) {
    if (i % 2 == 0) {
        pisk = 10;
    } else {
        pisk = 255;
    }
    square.setFillColor(Color(10, 10, pisk));
    mark.setFillColor(Color(10, 10, pisk));
    cobra->render(window, x, y, counter);
}