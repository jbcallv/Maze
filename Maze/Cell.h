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

	/*
	the cell rectangle
	*/
	sf::RectangleShape cellRect;


private:
	int x;
	int y;

	int cellWidth = 50;
	int cellHeight = 50;
};
#endif
