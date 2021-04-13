#include "Backtracker.h"

Backtracker::Backtracker(std::vector<std::vector<Cell>> mazeGrid) {
	this->m_mazeGrid = mazeGrid;
}

void Backtracker::deleteWall(Cell cell1, Cell cell2) {
	// delete wall between cell1 and cell2 where cell 2
	// is the cell to the left or below cell 1
	// remember that you can only pass in two adjacent cells

	// first check which cell is above or left of the other
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

	// might be neccessary to add conditionals where cell2 < cell1
}

sf::Vector2f Backtracker::generateRandomAdjacentCell(Cell cell) {
	// find all unvisited adjacent cells
	std::vector<Cell> adjacentNonVisited = findAdjacentCells(m_mazeGrid, cell);

	// generate a random cell
	int randCell = rand() % adjacentNonVisited.size();
	return sf::Vector2f(adjacentNonVisited.at(randCell).getPosX(), adjacentNonVisited.at(randCell).getPosY());
}

std::vector<Cell> Backtracker::findAdjacentCells(std::vector<std::vector<Cell>> mazeGrid, Cell cell) {
	int rows = HEIGHT / CELL_HEIGHT;
	int cols = WIDTH / CELL_WIDTH;

	int x = cell.getPosX();
	int y = cell.getPosY();

	std::vector<Cell> unvisited;

	// x and y are away from edge of maze
	if (x < rows && y < cols) {
		if (mazeGrid.at(x + 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x + 1).at(y));
		}
		if (mazeGrid.at(x - 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x - 1).at(y));
		}
		if (mazeGrid.at(x).at(y + 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y + 1));
		}
		if (mazeGrid.at(x).at(y - 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y - 1));
		}
	}

	// x is at edge but y is not
	else if (x == rows && y < cols) {
		if (mazeGrid.at(x - 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x - 1).at(y));
		}
		if (mazeGrid.at(x).at(y + 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y + 1));
		}
		if (mazeGrid.at(x).at(y - 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y - 1));
		}
	}

	// y is at edge but x is not
	else if (x < rows && y == cols) {
		if (mazeGrid.at(x).at(y - 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y - 1));
		}
		if (mazeGrid.at(x + 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x + 1).at(y));
		}
		if (mazeGrid.at(x - 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x - 1).at(y));
		}
	}

	// x and y are at edge (lower right corner)
	else if (x == rows && y == cols) {
		if (mazeGrid.at(x - 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x - 1).at(y));
		}
		if (mazeGrid.at(x).at(y - 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y - 1));
		}
	}

	// x is at left edge but y is not
	else if (x == 0 && y < cols) {
		if (mazeGrid.at(x + 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x + 1).at(y));
		}
		if (mazeGrid.at(x).at(y + 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y + 1));
		}
		if (mazeGrid.at(x).at(y - 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y - 1));
		}
	}

	// y is at upper edge but x is not
	else if (x < rows && y == 0) {
		if (mazeGrid.at(x).at(y + 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y + 1));
		}
		if (mazeGrid.at(x + 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x + 1).at(y));
		}
		if (mazeGrid.at(x - 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x - 1).at(y));
		}
	}

	// x and y in upper left corner
	else if (x == 0 && y == 0) {
		if (mazeGrid.at(x).at(y + 1).visited == false) {
			unvisited.push_back(mazeGrid.at(x).at(y + 1));
		}
		if (mazeGrid.at(x + 1).at(y).visited == false) {
			unvisited.push_back(mazeGrid.at(x + 1).at(y));
		}
	}

	return unvisited;
}
