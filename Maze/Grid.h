#pragma once
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"

class Grid {
public:

	/*
	holds the maze as a vector
	*/
	std::vector<std::vector<Cell>> mazeGrid;

	/*
	constructor to make
	a maze grid with n rows and cols
	*/
	Grid(int rows, int cols);

	/*
	draws all the cells
	*/
	void Draw(sf::RenderWindow& window);

	void generateCells();

private:
	int rows;
	int cols;
};
#endif
