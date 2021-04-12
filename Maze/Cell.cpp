#include "Cell.h"

Cell::Cell(int x, int y) {
	this->x = x;
	this->y = y;
	this->cellRect = sf::RectangleShape(sf::Vector2f(cellWidth - 5, cellHeight - 5));
	this->cellRect.setFillColor(sf::Color::Blue);
	this->cellRect.setPosition(sf::Vector2f(this->x * this->cellWidth, this->y * this->cellHeight));
}
