#include <SFML/Graphics.hpp>
#include "Constants.h"
// REMEMBER TO INCLUDE *.h files and not *.cpp files!!

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Maze");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}

void Update(float dt) {
    // update all stuff
}

void Draw(sf::RenderWindow& window) {
    // draw all game stuff
}