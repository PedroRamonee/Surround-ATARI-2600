#include "game.hpp"
#include "player.hpp"
#include "menu.hpp"

int main() {
  RenderWindow window(VideoMode(700, 700), "SURROUND!!!");

  PlayerOne cobra(&window, Color::Blue);
  PlayerTwo cobra2(&window, Color::Red);
  Event event;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
      }
    }

    cobra.changePosition(&window);
    cobra2.changePosition(&window);

    window.clear();
    cobra.render(&window);
    cobra2.render(&window);
    window.display();
    sleep(milliseconds(10.0f));
  }
  return 0 ;
}
