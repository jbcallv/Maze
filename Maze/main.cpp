#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Grid.h"
// REMEMBER TO INCLUDE *.h files and not *.cpp files!!

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Maze");
    Grid grid(height / 50, width / 50);
    grid.generateCells();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        grid.Draw(window);
        window.display();
    }

    return 0;
}

void Update(float dt) {
    // update all stuff
}
