#pragma once
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Cell.h"
#include "Backtracker.h"

class Grid {
public:

	/*
	holds the maze as a vector
	*/
	//std::vector<std::vector<Cell>> mazeGrid;
	//int mazeGrid[][];
	Cell** mazeGrid;

	/*
	constructor to make
	a maze grid with n rows and cols
	*/
	Grid(int rows, int cols, int seed);

	/*
	class destructor is neccessary
	*/
	~Grid();

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
	runs one step of the backtracker algorithm
	*/
	void stepBacktracker();

	/*
	deletes a wall between c1
	and c2
	*/
	void deleteWall(Cell* cell1, Cell* cell2);

private:
	// rows and columns in maze
	int rows;
	int cols;
	int seed;
	int visited;

	Backtracker backtracker;
	Cell curCell;
};
#endif
