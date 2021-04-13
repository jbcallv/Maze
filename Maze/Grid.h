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

	/*
	generates the cells for the
	maze
	*/
	void generateCells();

	/*
	generates the cell at which to start
	*/
	sf::Vector2f generateStartingCellBacktracker();

	/*
	runs the backtracker algorithm
	*/
	void backtracker();

private:
	// rows and columns in maze
	int rows;
	int cols;
};
#endif
