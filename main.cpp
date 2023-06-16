#include "src/start.hpp"


int main() {
    
    Start *jogo = new Start;
    jogo->runGame();
    delete jogo;
    jogo = nullptr;
   return EXIT_SUCCESS ;

}
