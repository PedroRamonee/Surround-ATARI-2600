/*
 * game.cpp
 *
 *  Created on: 26 de mai. de 2023
 *      Author: joaoc
 */

#include "game.hpp"

void Snake::render(RenderWindow *window) {
    /*
     Retorna void

     - Desenha os quadrados na tela
     */

    setBoard();

    for (unsigned int y = 0; y < this->grid.size(); y++) {
        for (unsigned int x = 0; x < this->grid[y].size(); x++) {
            if (grid[x][y]) {
                mark.setPosition(Vector2f(boltx * x, bolty * y));

                Color currentColor = mark.getFillColor();

                if (x == 0 || x == 29 || y == 0 || y == 29) {
                    mark.setFillColor(Color(0, 255, 0));
                }

                window->draw(mark);

                mark.setFillColor(currentColor);
            }
        }
    }

    window->draw(square);
}

void Snake::setMark(vector<vector<bool>> grid, bool *end) {
    /*
      Retorna void

      - Encontra a posição na matriz referente a posição na janela
      - Define a posição como true

      */

    arrayPosX = posx / boltx;
    arrayPosY = posy / bolty;

    if (this->grid[arrayPosX][arrayPosY] == false &&
        grid[arrayPosX][arrayPosY] == false) {
        this->grid[arrayPosX][arrayPosY] = true;
    } else {
        if (posx != startPosX || posy != startPosY) {
            *end = true;
        }
    }
}

void Snake ::setBoard() {
    for (int i = 0; i < 30; i++) {
        grid[i][0] = true;
        grid[0][i] = true;
        grid[i][29] = true;
        grid[29][i] = true;
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

vector<vector<bool>> Snake ::returnGrid() { return grid; }

void Snake ::resetGrid() {
    for (unsigned int y = 0; y < this->grid.size(); y++) {
        for (unsigned int x = 0; x < this->grid[y].size(); x++) {
            if (grid[x][y]) {
                grid[x][y] = false;
            }
        }
    }
}

void Snake ::posReset(RenderWindow *window) {
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
}

void Snake ::pauseSpeed() {
    velx = 0;
    vely = 0;
}