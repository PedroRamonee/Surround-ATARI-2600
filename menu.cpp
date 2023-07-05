#include "menu.hpp"
menu::menu(RenderWindow *window) {
    /* Construtor do Objeto Menu(-)

     - Configura a posição x e y inicial
     - Carrega imagens de background/icone
     - Carrega arquivos de música de music/start
     - Carrega a fonte*/

    this->altura = 100;

    this->inicio.openFromFile("assets/inicio.wav");
    inicio.play();
    inicio.setVolume(altura);

    this->marca[0].loadFromFile("assets/mpl1.jpg");
    this->marca[1].loadFromFile("assets/mpl2.jpg");
    this->marca[2].loadFromFile("assets/mpl3.jpg");
    this->marca[3].loadFromFile("assets/mpl4.jpg");
    this->marca[4].loadFromFile("assets/mpl5.jpg");
    this->marca[5].loadFromFile("assets/mpl6.jpg");
    for (int i = 0; i < 6; i++) {
        Sprite marquinha;
        marquinha.setTexture(marca[i]);
        window->draw(marquinha);
        window->display();
        sleep(seconds(0.32f));
    }
    sleep(Time(seconds(2.5f)));

    this->backgroundd.loadFromFile("assets/background.jpg");

    this->positionx = window->getSize().x;
    this->positiony = window->getSize().y;

    this->count = 0;

    this->countRestart = 0;

    this->start.openFromFile("assets/startdojogo.wav");

    this->music.openFromFile("assets/menumusic.wav");
    music.play();
    music.setVolume(altura-80);
    music.setLoop(true);

    this->credito.loadFromFile("assets/creditos.jpg");

    this->reinicio.loadFromFile("assets/restartimage.jpg");

    this->number[0].loadFromFile("assets/1.jpg");
    this->number[1].loadFromFile("assets/2.jpg");
    this->number[2].loadFromFile("assets/3.jpg");
    this->number[3].loadFromFile("assets/4.jpg");
    this->number[4].loadFromFile("assets/5.jpg");

    this->tema.openFromFile("assets/ingame.wav");
}
void menu::background(RenderWindow *window) {
    Sprite sprite;
    sprite.setTexture(backgroundd);
    window->draw(sprite);
}

void menu::creditos(RenderWindow *window, int *control) {
    Sprite spritecredito;
    spritecredito.setTexture(credito);
    window->draw(spritecredito);
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        *control = 1;
    }
}

void menu::botaum(RenderWindow *window, int *control) {
    if (Keyboard::isKeyPressed(Keyboard::Down) &&
        relogio.getElapsedTime().asMilliseconds() > 200) {
        count++;
        relogio.restart();
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) &&
        relogio.getElapsedTime().asMilliseconds() > 200) {
        count--;
        relogio.restart();
    }
    if (count > 2) {
        count = 0;
    }
    if (count < 0) {
        count = 2;
    }
    if (count == 0) {
        botao[0].setSize(Vector2f(500, 75));
        botao[0].setPosition(Vector2f(200, 405));
        botao[0].setFillColor(Color(0, 0, 0, 0));
        botao[0].setOutlineColor(Color(255, 255, 255));
        botao[0].setOutlineThickness(10);
        window->draw(botao[0]);
    }
    if (count == 1) {
        botao[1].setSize(Vector2f(500, 110));
        botao[1].setPosition(Vector2f(200, 505));
        botao[1].setFillColor(Color(0, 0, 0, 0));
        botao[1].setOutlineColor(Color(255, 255, 255));
        botao[1].setOutlineThickness(10);
        window->draw(botao[1]);
    }
    if (count == 2) {
        botao[2].setSize(Vector2f(500, 75));
        botao[2].setPosition(Vector2f(200, 640));
        botao[2].setFillColor(Color(0, 0, 0, 0));
        botao[2].setOutlineColor(Color(255, 255, 255));
        botao[2].setOutlineThickness(10);
        window->draw(botao[2]);
    }
    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
        switch (count) {
            case 0:
                *control = 0;
                music.pause();
                start.play();
                start.setVolume(altura);
                for (int i = 5; i >= 0; i--) {
                    Sprite numero;
                    numero.setTexture(number[i]);
                    window->draw(numero);
                    window->display();
                    sleep(seconds(0.6f));
                }
                tema.play();
                tema.setLoop(true);
                tema.setVolume(altura - 80);
                break;
            case 1:
                *control = 2;
                break;
            case 2:
                *control = 3;
                break;
        }
    }
}

void menu::restart(RenderWindow *window) {
    tema.pause();
    Sprite sprite;
    sprite.setTexture(reinicio);
    window->draw(sprite);
}

void menu::botaumRestart(RenderWindow *window, int *control, bool *reset) {
    {
        if (Keyboard::isKeyPressed(Keyboard::Down) &&
            relogio.getElapsedTime().asMilliseconds() > 200) {
            countRestart++;
            relogio.restart();
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) &&
            relogio.getElapsedTime().asMilliseconds() > 200) {
            countRestart--;
            relogio.restart();
        }
        if (countRestart > 1) {
            countRestart = 0;
        }
        if (countRestart < 0) {
            countRestart = 1;
        }
        if (countRestart == 0) {
            botaorestart[0].setSize(Vector2f(500, 75));
            botaorestart[0].setPosition(Vector2f(200, 443));
            botaorestart[0].setFillColor(Color(0, 0, 0, 0));
            botaorestart[0].setOutlineColor(Color(255, 255, 255));
            botaorestart[0].setOutlineThickness(10);
            window->draw(botaorestart[0]);
        }
        if (countRestart == 1) {
            botaorestart[1].setSize(Vector2f(500, 75));
            botaorestart[1].setPosition(Vector2f(200, 645));
            botaorestart[1].setFillColor(Color(0, 0, 0, 0));
            botaorestart[1].setOutlineColor(Color(255, 255, 255));
            botaorestart[1].setOutlineThickness(10);
            window->draw(botaorestart[1]);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
        switch (countRestart) {
            case 0:
                *control = 1;
                *reset = true;

                break;
            case 1:
                *control = 3;
                break;
        }
    }
}

void menu::pauseTema() { tema.pause(); }