#include "Backtracker.h"

Backtracker::Backtracker() {
}

// change to pass by reference
void Backtracker::deleteWall(Cell**& mazeGrid, Cell cell1, Cell cell2) {
	// delete wall between cell1 and cell2 where cell 2
	// is the cell to the right of or below cell 1
	// remember that you can only pass in two adjacent cells

	if (cell2.getPosX() == cell1.getPosX()) {
		if (cell2.getPosY() > cell1.getPosY() && cell2.wall == TOP_AND_LEFT) {
			std::cout << "delete 1" << std::endl;
			cell2.wall = LEFT;
			cell2.visited = true;
			mazeGrid[cell2.getPosX()][cell2.getPosY()] = cell2;
		}
		else if (cell2.getPosY() > cell1.getPosY() && cell2.wall == TOP) {
			std::cout << "delete 2" << std::endl;
			cell2.wall = NO_WALL;
			cell2.visited = true;
			mazeGrid[cell2.getPosX()][cell2.getPosY()] = cell2;
		}
		else if (cell2.getPosY() > cell1.getPosY() && cell2.wall == LEFT) {
			std::cout << "deletey" << std::endl;
			cell2.wall = LEFT;
			cell2.visited = true;
			mazeGrid[cell2.getPosX()][cell2.getPosY()] = cell2;
		}
		// CAUSES WALL TO REAPPAER
		else if (cell1.getPosY() > cell2.getPosY() && cell1.wall == TOP_AND_LEFT) {
			std::cout << "delete a" << std::endl;
			cell1.wall = LEFT;
			//cell1.visited = true;
			cell2.visited = true;
			//mazeGrid[cell2.getPosX()][cell2.getPosY()].visited = true;
			mazeGrid[cell2.getPosX()][cell2.getPosY()] = cell2;
			mazeGrid[cell1.getPosX()][cell1.getPosY()] = cell1;
		}
		else if (cell1.getPosY() > cell2.getPosY() && cell1.wall == TOP) {
			std::cout << "delete b" << std::endl;
			cell1.wall = NO_WALL;
			mazeGrid[cell2.getPosX()][cell2.getPosY()].visited = true;
			mazeGrid[cell1.getPosX()][cell1.getPosY()] = cell1;
		}
		else if (cell1.getPosY() > cell2.getPosY() && cell1.wall == LEFT) {
			std::cout << "dlety" << std::endl;
			cell1.wall = LEFT;
			mazeGrid[cell2.getPosX()][cell2.getPosY()].visited = true;
			mazeGrid[cell1.getPosX()][cell1.getPosY()] = cell1;
		}
	}

	else if (cell2.getPosY() == cell1.getPosY()) {
		if (cell2.getPosX() > cell1.getPosX() && cell2.wall == TOP_AND_LEFT) {
			std::cout << "delete 3" << std::endl;
			cell2.wall = TOP;
			cell2.visited = true;
			mazeGrid[cell2.getPosX()][cell2.getPosY()] = cell2;
		}
		else if (cell2.getPosX() > cell1.getPosX() && cell2.wall == LEFT) {
			std::cout << "delete 4" << std::endl;
			cell2.wall = NO_WALL;
			cell2.visited = true;
			mazeGrid[cell2.getPosX()][cell2.getPosY()] = cell2;
		}
		else if (cell2.getPosX() > cell1.getPosX() && cell2.wall == TOP) {
			std::cout << "delete 5" << std::endl;
			cell2.wall = TOP;
			cell2.visited = true;
			mazeGrid[cell2.getPosX()][cell2.getPosY()] = cell2;
		}
		// CAUSES WALL TO REAPPEAR
		else if (cell1.getPosX() > cell2.getPosX() && cell1.wall == TOP_AND_LEFT) {
			std::cout << "delete c" << std::endl;
			// CHANGES WALL TO LEFT BUT THEN ENTER NEXT DELETION LIKE IT HAS A TOP_AND_LEFT WALL!!!
			cell1.wall = LEFT;
			cell2.visited = true;
			//mazeGrid[cell2.getPosX()][cell2.getPosY()].visited = true;
			mazeGrid[cell2.getPosX()][cell2.getPosY()] = cell2;
			mazeGrid[cell1.getPosX()][cell1.getPosY()] = cell1;
		}
		else if (cell1.getPosX() > cell2.getPosX() && cell1.wall == LEFT) {
			std::cout << "delete d" << std::endl;
			cell1.wall = NO_WALL;
			mazeGrid[cell2.getPosX()][cell2.getPosY()].visited = true;
			mazeGrid[cell1.getPosX()][cell1.getPosY()] = cell1;
		}
		else if (cell1.getPosX() > cell2.getPosX() && cell1.wall == TOP) {
			std::cout << "delete e" << std::endl;
			cell1.wall = TOP;
			mazeGrid[cell2.getPosX()][cell2.getPosY()].visited = true;
			mazeGrid[cell1.getPosX()][cell1.getPosY()] = cell1;
		}
	}
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
	// change to rows - 1?
	int rows = (HEIGHT / CELL_HEIGHT) - 1;
	int cols = (WIDTH / CELL_WIDTH) - 1;

	int x = cell.getPosX();
	int y = cell.getPosY();
	//std::cout << "x: " << x << ", " << "y: " << y << std::endl;

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
		// we weren't stopping, haha. New: return statement in each outer conditional
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
		//std::cout << "third if" << std::endl;
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
		//std::cout << "fourth if" << std::endl;
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
		//std::cout << "fifth if" << std::endl;
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
		//std::cout << "sixth if" << std::endl;
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
		//std::cout << "seventh if" << std::endl;
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
