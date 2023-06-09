#include "game.hpp"
#include "player.hpp"


class Start{

private:
    PlayerOne *cobra;
    PlayerTwo *cobra2;
    RenderWindow *window;

public:

    Start(RenderWindow *window);
    ~Start();
    void Restart();
    void Update();
    void Draw();
};