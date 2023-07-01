#include "start.hpp"

Start::Start() { window.create(VideoMode(900, 900), "SURROUND!!!"); }

Start::~Start() {}

void Start::Update(PlayerOne *cobra, PlayerTwo *cobra2) {
    cobra->changePosition(&window);
    cobra2->changePosition(&window);
}

void Start::Draw(PlayerOne *cobra, PlayerTwo *cobra2) {
    cobra->render(&window);
    cobra2->render(&window);
}

void Start::runGame() {
    Event event;

    menu Menu(&window);

    PlayerOne cobra(&window, Color::Blue);
    PlayerTwo cobra2(&window, Color::Red);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            {
                if (event.type == Event::Closed ||
                    Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();
            }
        }

        switch (controller) {
            case 0:
                Update(&cobra, &cobra2);

                window.clear();

                Draw(&cobra, &cobra2);

                window.display();
                sleep(milliseconds(10.0f));
                break;

            case 1:
                window.clear();
                Menu.background(&window);
                window.display();

                break;

            case 2:

                break;
        }
    }
}