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
    int velx = 0, vely = 0;
    RectangleShape square;
    RectangleShape mark;
    int posx = 0, posy = 0;
    int arrayPosX = 0, arrayPosY = 0;
    int boltx;
    int bolty;
    int pisk = 100;
    int f = 0;
    vector<vector<bool>> grid;
    bool end = false;

   public:
    void render(RenderWindow *window);

    void setMark();

    void setBoard();

    bool returnEnd();

    
};

#endif /* GAME_HPP_ */
