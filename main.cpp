#include "src/game.hpp"
#include "src/menu.hpp"
#include "src/start.hpp"

int main() {
  RenderWindow window(VideoMode(700, 700), "SURROUND!!!");

  Start game(&window);

  Event event;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
      }
    }

    
    game.Update();

    window.clear();

    game.Draw();

    window.display();

    sleep(milliseconds(10.0f));
  }
  return 0 ;
}
