#include "start.hpp"

Start::Start() {
    this->reiniciomusica.openFromFile("assets/restartmusic.wav");
    reiniciomusica.setLoop(true);
    reiniciomusica.setVolume(25.f);
    this->colisaosound.openFromFile("assets/somDeColisao.wav");
    colisaosound.setVolume(100.f);
    this->knocout.openFromFile("assets/knocout.wav");
    knocout.setVolume(100.f);
    this->ganha[0].loadFromFile("assets/player1.jpg");
    this->ganha[1].loadFromFile("assets/player2.jpg");
}

Start::~Start() {}

void Start::Update(PlayerOne *cobra, PlayerTwo *cobra2, RenderWindow *window) {
    cobra->changePosition(window, cobra2->returnGrid(), &end, &pointer2);
    cobra2->changePosition(window, cobra->returnGrid(), &end, &pointer1);
}

void Start::Draw(PlayerOne *cobra, PlayerTwo *cobra2, RenderWindow *window) {
    cobra->render(window, x, y, counter, pointer1, pointer2);
    cobra2->render(window, x, y, counter, pointer1, pointer2);
}

void Start::changeCor(RenderWindow *window, PlayerOne *cobra,
                      PlayerTwo *cobra2) {
    colisaosound.setLoop(true);
    colisaosound.play();
    for (int i = 0; i < 8; i++) {
        cobra->changeColor(window, cobra, i, x, y, counter, pointer1, pointer2);
        cobra2->changeColor(window, cobra2, i, x, y, counter, pointer1,
                            pointer2);
        window->display();
        sleep(seconds(0.3f));
    }
    colisaosound.stop();
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

void Start::setPedra(PlayerOne *cobra, PlayerTwo *cobra2) {
    if (counter != 0) {
        for (int i = 0; i <= (2 * counter); i++) {
            int a = (rand() % (cobra->returnGridSize() - 2)) + 1;
            int b = (rand() % (cobra->returnGridSize() - 2)) + 1;

            if (a != cobra->returnPosX() && b != cobra->returnPosY() ||
                a != cobra2->returnPosX() && b != cobra2->returnPosY()) {
                x[i] = a;
                y[i] = b;
            } else {
                x[i] = (rand() % (cobra->returnGridSize() - 2)) + 1;
                y[i] = (rand() % (cobra->returnGridSize() - 2)) + 1;
            }

            cobra->setGrid(x[i], y[i], counter);
            cobra2->setGrid(x[i], y[i], counter);
        }
    }
}
void Start::setSpeed(PlayerOne *cobra, PlayerTwo *cobra2) {
    cobra->pauseSpeed();
    cobra2->pauseSpeed();
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
                    if (pointer1 == 3 || pointer2 == 3) {
                        controller = 4;
                        count = 0;
                        Menu->pauseTema();
                        if (pointer1 == 3) {
                            window->clear();
                            Sprite sprite;
                            sprite.setTexture(ganha[0]);
                            knocout.play();
                            window->draw(sprite);
                            window->display();
                            sleep(seconds(2.0f));
                        }
                        if (pointer2 == 3) {
                            window->clear();
                            Sprite sprite;
                            sprite.setTexture(ganha[1]);
                            knocout.play();
                            window->draw(sprite);
                            window->display();
                            sleep(seconds(2.0f));
                        }
                        reiniciomusica.play();
                    } else {
                        changeCor(window, cobra, cobra2);

                        gridReset(cobra, cobra2);
                        positionReset(window, cobra, cobra2);
                        setPedra(cobra, cobra2);
                        setSpeed(cobra, cobra2);
                        counter++;
                    }
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

                    Start *jogo = new Start;
                    reiniciomusica.pause();
                    jogo->runGame(window);
                    delete jogo;
                }

                break;
        }
    }
}