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
   protected:
    int velx = 0;
    int vely = 0;
    RectangleShape square;
    RectangleShape mark;
    int posx = 0;
    int posy = 0;
    int arrayPosX = 0;
    int arrayPosY = 0;
    int startPosX = 0;
    int startPosY = 0;
    int boltx;
    int bolty;
    int pisk = 100;
    int countColor = 0;
    vector<vector<bool>> grid;

    Clock clock;

   public:
    void render(RenderWindow *window, int a[], int b[], int counter,
                int pointer1, int pointer2);

    void setMark(vector<vector<bool>> grid, bool *end, int *pointer);

    void setBoard();

    vector<vector<bool>> returnGrid();

    void resetGrid();

    void posReset(RenderWindow *window);

    void pauseSpeed();

    void setGrid(int x, int y);

    size_t returnGridSize();

    int returnPosX();

    int returnPosY();
};

#endif /* GAME_HPP_ */
