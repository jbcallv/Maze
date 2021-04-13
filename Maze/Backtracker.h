#pragma once
#ifndef BACTRACKER_H
#define BACKTRACKER_H

#include <vector>
#include <stack>
#include "Cell.h"
#include "Constants.h"

class Backtracker {
public:

	/*
	non-default constructor which uses the
	maze grid
	*/
	Backtracker(std::vector<std::vector<Cell>> mazeGrid);

	/*
	default constructor so we can
	call methods in this class and pass in the mazegrid
	*/
	Backtracker();

	/*
	deletes a wall separating two cells
	*/
	void deleteWall(Cell cell1, Cell cell2);

	/*
	returns a vector holding
	a randomly generated cell location
	*/
	sf::Vector2f generateRandomAdjacentCell(Cell cell, std::vector<std::vector<Cell>> m_mazeGrid);

	/*
	finds all adjacent
	cells that haven't been visited
	*/
	std::vector<Cell> findAdjacentCells(std::vector<std::vector<Cell>> mazeGrid, Cell cell);

	/*
	the stack to which we push
	cells for backtracking
	*/
	std::stack<Cell> cellStack;

	// reset mazeGrid from grid.cpp to this on each wall deletion
	//std::vector<std::vector<Cell>> m_mazeGrid;
private:
	//std::vector<std::vector<Cell>> m_mazeGrid;
};

#endif
