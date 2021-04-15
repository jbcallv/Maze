#include "Backtracker.h"

Backtracker::Backtracker(std::vector<std::vector<Cell>> mazeGrid) {
}

Backtracker::Backtracker() {
}

// change to pass by reference
void Backtracker::deleteWall(Cell cell1, Cell cell2) {
	// delete wall between cell1 and cell2 where cell 2
	// is the cell to the right of or below cell 1
	// remember that you can only pass in two adjacent cells

	// first check which cell is above or left of the other

	// pass by value problem. Cell2 is modified here but not in Grid.cpp:98
	if (cell2.getPosY() > cell1.getPosY() && cell2.wall == TOP_AND_LEFT) {
		cell2.wall = LEFT;
	}
	
	else if (cell2.getPosY() > cell1.getPosY() && cell2.wall == TOP) {
		cell2.wall = NO_WALL;
	}

	else if (cell2.getPosX() > cell1.getPosX() && cell2.wall == TOP_AND_LEFT) {
		cell2.wall = TOP;
	}

	else if (cell2.getPosX() > cell1.getPosX() && cell2.wall == LEFT) {
		cell2.wall = NO_WALL;
	}

	// pass by value problem 2: cell1 needs to be set to cell 2 here
}

Cell Backtracker::generateRandomAdjacentCell(Cell cell, Cell **m_mazeGrid) {
	// find all unvisited adjacent cells
	std::vector<Cell> adjacentNonVisited = findAdjacentCells(m_mazeGrid, cell);

	// generate a random cell
	int randCell = rand() % adjacentNonVisited.size();
	return adjacentNonVisited.at(randCell);
}

std::vector<Cell> Backtracker::findAdjacentCells(Cell **mazeGrid, Cell cell) {
	int rows = WIDTH / CELL_HEIGHT;
	int cols = HEIGHT / CELL_WIDTH;

	int x = cell.getPosX();
	int y = cell.getPosY();
	std::cout << "x: " << x << ", " << "y: " << y << std::endl;

	std::vector<Cell> unvisited;

	// x and y are away from edge of maze
	if (x > 0 && x < rows && y < cols && y > 0) {
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
	}

	// x is at edge but y is not
	else if (x == rows && y < cols && y > 0) {
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y + 1]);
		}
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
	}

	// y is at edge but x is not
	else if (x < rows && x > 0 && y == cols) {
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x + 1][y]);
		}
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
	}

	// x and y are at edge (lower right corner)
	else if (x == rows && y == cols) {
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
	}

	// x is at left edge but y is not
	else if (x == 0 && y < cols && y > 0) {
		std::cout << "x is at left edge but y is not" << std::endl;

		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y + 1]);
		}
		if (mazeGrid[x][y - 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
	}

	// y is at upper edge but x is not
	else if (x < rows && x > 0 && y == 0) {
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x + 1][y]);
		}
		if (mazeGrid[x - 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x - 1][y]);
		}
	}

	// x and y in upper left corner
	else if (x == 0 && y == 0) {
		if (mazeGrid[x][y + 1].visited == false) {
			unvisited.push_back(mazeGrid[x][y - 1]);
		}
		if (mazeGrid[x + 1][y].visited == false) {
			unvisited.push_back(mazeGrid[x + 1][y]);
		}
	}

	return unvisited;
}

Cell Backtracker::findRightOrBelow(Cell cell1, Cell cell2) {
	if (cell1.getPosX() > cell2.getPosX() || cell1.getPosY() > cell2.getPosY()) {
		return cell1;
	}
	else {
		return cell2;
	}
}

Cell Backtracker::findLeftOrAbove(Cell cell1, Cell cell2) {
	if (cell1.getPosX() < cell2.getPosX() || cell1.getPosY() < cell2.getPosY()) {
		return cell1;
	}
	else {
		return cell2;
	}
}
