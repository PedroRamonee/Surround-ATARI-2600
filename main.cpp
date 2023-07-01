#include <ctime>

#include "src/start.hpp"

int main() {
    srand(time(NULL));
    Start *jogo = new Start;
    jogo->runGame();
    delete jogo;
    jogo = nullptr;
    return 0;
}
