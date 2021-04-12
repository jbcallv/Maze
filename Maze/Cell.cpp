#include "Cell.h"

Cell::Cell(int x, int y, int walls) {
	this->x = x;
	this->y = y;
	this->wall = walls;
	/*this->cellRect = sf::RectangleShape(sf::Vector2f(cellWidth, cellHeight));
	this->cellRect.setFillColor(sf::Color::Blue);
	this->cellRect.setPosition(sf::Vector2f(this->x * this->cellWidth, this->y * this->cellHeight));*/

	this->generateWalls();
}

void Cell::generateWalls() {
	// cell has only a left wall
	if (wall == LEFT) {
		leftWall = sf::RectangleShape(sf::Vector2f(WALL_WIDTH, cellHeight));
		leftWall.setFillColor(sf::Color::Black);
		leftWall.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));
	}

	// cell has only a top wall
	else if (wall == TOP) {
		topWall = sf::RectangleShape(sf::Vector2f(cellWidth, WALL_WIDTH));
		topWall.setFillColor(sf::Color::Black);
		topWall.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));
	}

	// cell has both a top and left wall
	else if (wall == TOP_AND_LEFT) {
		topWall = sf::RectangleShape(sf::Vector2f(cellWidth, WALL_WIDTH));
		topWall.setFillColor(sf::Color::Black);
		topWall.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));

		leftWall = sf::RectangleShape(sf::Vector2f(WALL_WIDTH, cellHeight));
		leftWall.setFillColor(sf::Color::Black);
		leftWall.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));
	}
}
