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
	default constructor so we can
	call methods in this class and pass in the mazegrid
	*/
	Backtracker();

	/*
	deletes a wall separating two cells
	*/
	void deleteWall(Cell**& mazeGrid, Cell cell1, Cell cell2);

	/*
	generates random adjacent cell
	*/
	Cell generateRandomAdjacentCell(Cell cell, Cell** m_mazeGrid);

	/*
	finds adjacent cells
	*/
	std::vector<Cell> findAdjacentCells(Cell** mazeGrid, Cell cell);

	/*
	the stack to which we push
	cells for backtracking
	*/
	std::stack<Cell> cellStack;

private:
};

#endif
