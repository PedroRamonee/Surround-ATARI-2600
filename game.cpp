/*
 * game.cpp
 *
 *  Created on: 26 de mai. de 2023
 *      Author: joaoc
 */

#include "game.hpp"

int main() {
  RenderWindow window(VideoMode(600, 600), "SURROUND!!!");

  Snake cobra(&window, Color::Blue);

  Event event;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
      }
    }

    cobra.changePosition(&window);

    window.clear();
    cobra.render(&window);
    window.display();
    sleep(milliseconds(10.0f));
  }

  return 0;
}
