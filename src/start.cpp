#include "start.hpp"

Start::Start() {
    this->reiniciomusica.openFromFile("assets/restartmusic.wav");
    reiniciomusica.setLoop(true);
    reiniciomusica.setVolume(25.f);
}

Start::~Start() {}

void Start::Update(PlayerOne *cobra, PlayerTwo *cobra2, RenderWindow *window) {
    cobra->changePosition(window, cobra2->returnGrid(), &end);
    cobra2->changePosition(window, cobra->returnGrid(), &end);
}

void Start::Draw(PlayerOne *cobra, PlayerTwo *cobra2, RenderWindow *window) {
    cobra->render(window);
    cobra2->render(window);
}

void Start::changeColor(RenderWindow *window, PlayerOne *cobra,
                        PlayerTwo *cobra2) {
    for (int i = 0; i < 6; i++) {
        cobra->changeColor(window, cobra, i);
        cobra2->changeColor(window, cobra2, i);
        window->display();
        sleep(seconds(0.5f));
    }
}

void Start ::gridReset(PlayerOne *cobra, PlayerTwo *cobra2) {
    cobra->resetGrid();
    cobra2->resetGrid();
}

void Start::positionReset(RenderWindow *window, PlayerOne *cobra,
                          PlayerTwo *cobra2) {
    cobra->posReset(window);
    cobra2->posReset(window);
}

void Start::runGame(RenderWindow *window) {
    Event event;

    menu *Menu = new menu(window);

    PlayerOne *cobra = new PlayerOne(window, Color::Blue);
    PlayerTwo *cobra2 = new PlayerTwo(window, Color::Red);

    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            {
                if (event.type == Event::Closed) {
                    window->close();
                }
            }
        }

        switch (controller) {
            case 0:

                Update(cobra, cobra2, window);
                window->clear();
                Draw(cobra, cobra2, window);
                window->display();
                if (end == true) {
                    count++;
                    if (count == 3) {
                        controller = 4;
                        count = 0;
                        Menu->pauseTema();
                        reiniciomusica.play();
                    }
                    changeColor(window, cobra, cobra2);

                    gridReset(cobra, cobra2);
                    positionReset(window, cobra, cobra2);

                    cobra->pauseSpeed();
                    cobra2->pauseSpeed();

                    end = false;
                }

                break;

            case 1:
                window->clear();
                Menu->background(window);
                Menu->botaum(window, &controller);
                window->display();

                break;

            case 2:
                window->clear();
                Menu->creditos(window, &controller);
                window->display();

                break;

            case 3:

                delete cobra;
                delete cobra2;
                window->close();

                break;
            case 4:

                window->clear();
                Menu->restart(window);
                Menu->botaumRestart(window, &controller, &reset);
                window->display();

                if (reset == true) {
                    delete cobra;
                    delete cobra2;

                    delete Menu;

                    Start *jogo = new Start;
                    reiniciomusica.pause();
                    jogo->runGame(window);
                    delete jogo;
                }

                break;
        }
    }
}