#include "start.hpp"

Start::Start() {}

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
    for (int i = 0; i < 8; i++) {
        cobra->changeColor(window, cobra, i);
        cobra2->changeColor(window, cobra2, i);
        window->display();
        sleep(seconds(0.5f));
    }
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
                    controller = 4;

                    changeColor(window, cobra, cobra2);

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
                    jogo->runGame(window);
                    delete jogo;
                }

                break;
        }
    }
}