#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Grid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Maze", sf::Style::Titlebar | sf::Style::Close);
    Grid grid(HEIGHT / CELL_HEIGHT, WIDTH / CELL_WIDTH);
    grid.generateCells();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        grid.Draw(window);
        window.display();
    }

    return 0;
}

void Update(float dt) {
    // update all stuff
}
