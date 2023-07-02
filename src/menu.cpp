#include "menu.hpp"
menu::menu(RenderWindow *window) {
    /* Construtor do Objeto Menu(-)

     - Configura a posição x e y inicial
     - Carrega imagens de background/icone
     - Carrega arquivos de música de music/start
     - Carrega a fonte*/ 

    this->altura = 20;

    this->inicio.openFromFile("assets/inicio.wav");
    inicio.play();
    inicio.setVolume(altura);

    this->marca.loadFromFile("assets/marca.jpg");
    Sprite spritemarca;
    spritemarca.setTexture(marca);
    window->draw(spritemarca);
    window->display();

    sleep(Time(seconds(1.5)));

    this->icon.loadFromFile("assets/icone.png");

    this->backgroundd.loadFromFile("assets/background.jpg");

    this->positionx = window->getSize().x;
    this->positiony = window->getSize().y;

    this->count = 0;

    this->start.openFromFile("assets/startdojogo.wav");

    this->music.openFromFile("assets/menumusic.wav");
    music.play();
    music.setVolume(altura);
    music.setLoop(true);

    this->credito.loadFromFile("assets/creditos.jpg");

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

void menu::creditos(RenderWindow *window,int *control){
    Sprite spritecredito;
    spritecredito.setTexture(credito);
    window->draw(spritecredito);
    if(Keyboard::isKeyPressed(Keyboard::Escape)){
        *control=1;
    }
}

void menu::botaum(RenderWindow *window,int *control){
    
    if(Keyboard::isKeyPressed(Keyboard::Down)&&relogio.getElapsedTime().asMilliseconds()>200){
        count++;
        relogio.restart();
    }
    if(Keyboard::isKeyPressed(Keyboard::Up)&&relogio.getElapsedTime().asMilliseconds()>200){
        count--;
        relogio.restart();
    }
    if(count>2){
        count = 0;
    }
    if(count<0){
        count = 2;
    }
    if(count==0){
    botao[0].setSize(Vector2f(500,75));
    botao[0].setPosition(Vector2f(200,395));
    botao[0].setFillColor(Color(0,0,0,0));
    botao[0].setOutlineColor(Color(255,255,255));
    botao[0].setOutlineThickness(10);
    window->draw(botao[0]);
    }
    if(count==1){
    botao[1].setSize(Vector2f(500,110));
    botao[1].setPosition(Vector2f(200,505));
    botao[1].setFillColor(Color(0,0,0,0));
    botao[1].setOutlineColor(Color(255,255,255));
    botao[1].setOutlineThickness(10);
    window->draw(botao[1]);
    }
    if(count==2){
    botao[2].setSize(Vector2f(500,75));
    botao[2].setPosition(Vector2f(200,650));
    botao[2].setFillColor(Color(0,0,0,0));
    botao[2].setOutlineColor(Color(255,255,255));
    botao[2].setOutlineThickness(10);
    window->draw(botao[2]);
    }
    if(Keyboard::isKeyPressed(Keyboard::Enter)){
        switch (count){
        case 0:
        *control=0;
        music.pause();
        start.play();
        start.setVolume(altura);
        for(int i=0;i<5;i++){
            Sprite numero;
            numero.setTexture(number[i]);
             window->draw(numero);
             window->display();
             sleep(seconds(1.0f));
        }
        tema.play();
        tema.setLoop(true);
        tema.setVolume(altura);
        break;
        case 1:
        *control=2;
        break;
        case 2:
        *control=3;
        break;
        }    
    }
}







