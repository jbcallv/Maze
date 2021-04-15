#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Grid.h"

#include <thread>
#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Maze", sf::Style::Titlebar | sf::Style::Close);

    srand(time(0));
    Grid *grid = new Grid((int) HEIGHT / CELL_HEIGHT, (int) WIDTH / CELL_WIDTH, rand());
    grid->generateCells();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(UNVISITED);
        grid->stepBacktracker();
        grid->Draw(window);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    grid->~Grid();

    return 0;
}

void Update(float dt) {
    // update all stuff
}
