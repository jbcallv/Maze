#include "Backtracker.h"

Backtracker::Backtracker() {
}

Cell Backtracker::generateRandomAdjacentCell(Cell cell, Cell **m_mazeGrid) {
	// find all unvisited adjacent cells
	std::vector<Cell> adjacentNonVisited = findAdjacentCells(m_mazeGrid, cell);

	// generate a random cell
	if (adjacentNonVisited.size() > 0) {
		int randCell = rand() % adjacentNonVisited.size();
		return adjacentNonVisited.at(randCell);
	}
	throw 0;
}

std::vector<Cell> Backtracker::findAdjacentCells(Cell **mazeGrid, Cell cell) {
	int rows = (HEIGHT / CELL_HEIGHT) - 1;
	int cols = (WIDTH / CELL_WIDTH) - 1;

	// get coordinates of cell
	int x = cell.getPosX();
	int y = cell.getPosY();

	std::vector<Cell> unvisited;

	// x and y are away from edge of maze
	if (x > 0 && x < cols && y < rows && y > 0) {
		//std::cout << "first if" << std::endl;
		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x + 1][y]);
		}
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y + 1]);
		}
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
		return unvisited;
	}

	// x is at edge but y is not
	else if (x == cols && y < rows && y > 0) {
		//std::cout << "second if" << std::endl;
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y + 1]);
		}
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
		return unvisited;
	}

	// y is at edge but x is not
	else if (x < cols && x > 0 && y == rows) {
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x + 1][y]);
		}
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
		return unvisited;
	}

	// x and y are at edge (lower right corner)
	else if (x == cols && y == rows) {
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
		return unvisited;
	}

	// x is at left edge but y is not
	else if (x == 0 && y < rows && y > 0) {
		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x + 1][y]);
		}
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y + 1]);
		}
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
		return unvisited;
	}

	// y is at upper edge but x is not
	else if (x < cols && x > 0 && y == 0) {
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y + 1]);
		}
		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x + 1][y]);
		}
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
		return unvisited;
	}

	// x and y in upper left corner
	else if (x == 0 && y == 0) {
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y + 1]);
		}
		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x + 1][y]);
		}
		return unvisited;
	}

	return unvisited;
}
