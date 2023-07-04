#include <ctime>

#include "src/start.hpp"

int main() {
    RenderWindow window(VideoMode(900, 900), "SURROUND !!!!");
    srand(time(NULL));
    Start *jogo = new Start;
    jogo->runGame(&window);
    delete jogo;
    jogo = nullptr;
    return 0;
}
