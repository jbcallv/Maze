#include "Cell.h"

Cell::Cell(int x, int y, int walls) {
	this->x = x;
	this->y = y;
	this->wall = walls;
	// change this field as neccessary
	this->visited = false;
	// subtract 5 to account for wall width and height
	this->cellRect = sf::RectangleShape(sf::Vector2f(cellWidth - 5, cellHeight - 5));
	this->cellRect.setFillColor(UNVISITED);
	// add 5 to account for wall positions
	this->cellRect.setPosition(sf::Vector2f(this->x * this->cellWidth + 5, this->y * this->cellHeight + 5));

	this->generateWalls();
}

void Cell::generateWalls() {
	// cell has only a left wall
	if (wall == LEFT) {
		leftWall = sf::RectangleShape(sf::Vector2f(WALL_WIDTH, cellHeight));
		leftWall.setFillColor(WALL_COLOR);
		leftWall.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));
	}

	// cell has only a top wall
	else if (wall == TOP) {
		topWall = sf::RectangleShape(sf::Vector2f(cellWidth, WALL_WIDTH));
		topWall.setFillColor(WALL_COLOR);
		topWall.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));
	}

	// cell has both a top and left wall
	else if (wall == TOP_AND_LEFT) {
		topWall = sf::RectangleShape(sf::Vector2f(cellWidth, WALL_WIDTH));
		topWall.setFillColor(WALL_COLOR);
		topWall.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));

		leftWall = sf::RectangleShape(sf::Vector2f(WALL_WIDTH, cellHeight));
		leftWall.setFillColor(WALL_COLOR);
		leftWall.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));
	}

	else if (wall == NO_WALL) {
		// do nuhin!
	}
}

int Cell::getPosX() {
	return this->x;
}

int Cell::getPosY() {
	return this->y;
}
