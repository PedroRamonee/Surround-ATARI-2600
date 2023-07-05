#include <ctime>

#include "src/start.hpp"

int main() {
    RenderWindow window(VideoMode(900, 900), "Surround Remake");

    sf::Image image;
    image.loadFromFile("assets/icone.png");
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    srand(time(NULL));
    Start *jogo = new Start;
    jogo->runGame(&window);
    delete jogo;
    jogo = nullptr;
    return 0;
}
