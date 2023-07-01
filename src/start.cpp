#include "start.hpp"

Start::Start() {
    window.create(VideoMode(900, 900), "SURROUND!!!");
    this->cobra = new PlayerOne(&window, Color::Blue);
    this->cobra2 = new PlayerTwo(&window, Color::Red);
}

Start::~Start() {
    delete this->cobra;
    delete this->cobra2;
}

void Start::Update() {
    cobra->changePosition(&window);
    cobra2->changePosition(&window);
}

void Start::Draw() {
    cobra->render(&window);
    cobra2->render(&window);
}

void Start::runGame() {
    Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            {
                if (event.type == Event::Closed ||
                    Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();
            }
        }

        Update();

        window.clear();

        Draw();

        window.display();

        sleep(milliseconds(10.0f));
    }
}