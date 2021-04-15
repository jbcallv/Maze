#pragma once
#ifndef BACTRACKER_H
#define BACKTRACKER_H

#include <vector>
#include <stack>
#include <iostream>
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
	returns a randomly generated cell
	*/
	Cell generateRandomAdjacentCell(Cell cell, Cell **m_mazeGrid);

	/*
	finds all adjacent
	cells that haven't been visited
	*/
	std::vector<Cell> findAdjacentCells(Cell **mazeGrid, Cell cell);

	/*
	returns the cell that is to the right of or below
	the other
	*/
	Cell findRightOrBelow(Cell cell1, Cell cell2);

	/*
	returns the cell that is to the left of or above
	the other
	*/
	Cell findLeftOrAbove(Cell cell1, Cell cell2);

	/*
	the stack to which we push
	cells for backtracking
	*/
	std::stack<Cell> cellStack;

private:
};

#endif
