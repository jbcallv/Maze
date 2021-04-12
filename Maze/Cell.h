#pragma once
#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell {
public:
	/*
	constructor to make a cell
	at row x and column y
	*/
	Cell(int x, int y);

private:
	int x;
	int y;

	const int cellWidth = 50;
	const int cellHeight = 50;
	sf::RectangleShape cellRect;
};
#endif
