#pragma once
#ifndef BACTRACKER_H
#define BACKTRACKER_H

#include <vector>
#include <stack>
#include "Cell.h"

class Backtracker {
public:
	/*
	deletes a wall separating two cells
	*/
	void deleteWall(Cell cell1, Cell cell2);

	/*
	returns a vector holding
	a random cell index
	*/
	std::vector<int> generateRandomCell();

	/*
	the stack to which we push
	cells for backtracking
	*/
	std::stack<Cell> cellStack;
private:
};

#endif
