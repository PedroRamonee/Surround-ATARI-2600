#include "start.hpp"


Start::Start(RenderWindow* window){

    this->window = window;
    this->cobra = new PlayerOne(window, Color::Blue);
    this->cobra2 = new PlayerTwo(window, Color::Red);
    
}

Start::~Start(){

}

void Start:: Restart(){

    

}

void Start:: Update(){

    cobra->changePosition(this->window);
    cobra2->changePosition(this->window);
}

void Start::Draw() {

    cobra->render(this->window);
    cobra2->render(this->window);

}