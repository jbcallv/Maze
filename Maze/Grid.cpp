#include "Grid.h"

Grid::Grid(int rows, int cols, int seed) {
	this->rows = rows;
	this->cols = cols;
	this->seed = seed;
	this->visited = 0;

	// make this entire class more efficient by using a 1D array instead
	this->mazeGrid = new Cell*[cols];
	for (int i = 0; i < cols; ++i) {
		mazeGrid[i] = new Cell[rows];
	}
}

Grid::~Grid() {
	for (int i = 0; i < cols; ++i) {
		delete mazeGrid[i];
	}
	delete mazeGrid;
}

void Grid::Draw(sf::RenderWindow& window) {
	// iterate through cols first as col represents an x coordinate
	// and row represents a y coordinate
	int wallLoc;
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			// get the location of the wall
			wallLoc = mazeGrid[i][j].wall;
			if (wallLoc == TOP_AND_LEFT) {
				// draw top and left walls
				window.draw(mazeGrid[i][j].leftWall);
				window.draw(mazeGrid[i][j].topWall);

				if (mazeGrid[i][j].visited && mazeGrid[i][j].cellRect.getFillColor() != OUT_OF_STACK) {
					mazeGrid[i][j].cellRect.setFillColor(VISITED);
				}
				window.draw(mazeGrid[i][j].cellRect);
			}
			else if (wallLoc == TOP) {
				// only draw top wall
				window.draw(mazeGrid[i][j].topWall);
				if (mazeGrid[i][j].visited && mazeGrid[i][j].cellRect.getFillColor() != OUT_OF_STACK) {
					mazeGrid[i][j].cellRect.setFillColor(VISITED);
				}
				window.draw(mazeGrid[i][j].cellRect);
			}
			else if (wallLoc == LEFT) {
				// only draw left wall
				window.draw(mazeGrid[i][j].leftWall);
				if (mazeGrid[i][j].visited && mazeGrid[i][j].cellRect.getFillColor() != OUT_OF_STACK) {
					mazeGrid[i][j].cellRect.setFillColor(VISITED);
				}
				window.draw(mazeGrid[i][j].cellRect);
			}

			else if (wallLoc == NO_WALL) {
				// draw no wall
				if (mazeGrid[i][j].visited && mazeGrid[i][j].cellRect.getFillColor() != OUT_OF_STACK) {
					mazeGrid[i][j].cellRect.setFillColor(VISITED);
				}
				window.draw(mazeGrid[i][j].cellRect);
			}
		}
	}
}

void Grid::generateCells() {
	// TODO: use 1D array instead
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			// change last parameter to change wall location
			mazeGrid[i][j] = Cell(i, j, 3);
		}
	}
	sf::Vector2f startingPoint = generateStartingCellBacktracker();
	std::cout << startingPoint.x << ", " << startingPoint.y << std::endl;
	mazeGrid[(int) startingPoint.x][(int) startingPoint.y].visited = true;
	curCell = mazeGrid[(int)startingPoint.x][(int)startingPoint.y];
}

sf::Vector2f Grid::generateStartingCellBacktracker() {
	// x is cols and y is rows
	int x = rand() % cols;
	int y = rand() % rows;

	return (sf::Vector2f(x, y));
}

void Grid::stepBacktracker() {
	// takes one step in the backtracker algorithm
	if (visited < ((rows) * (cols))) {
		// if an adjacent cell exists
		if (backtracker.findAdjacentCells(mazeGrid, curCell).size() > 0) {
			// push current cell to stack
			backtracker.cellStack.push(curCell);

			// generate a random adjacent cell
			Cell chosenCell = backtracker.generateRandomAdjacentCell(curCell, mazeGrid);

			// remove wall between curCell and chosen cell
			deleteWall(&curCell, &chosenCell);

			// make chosen cell the curCell and mark it as visited
			chosenCell.visited = true;
			curCell = chosenCell;

			// increment num of cells visited
			visited++;
		}
		// else if stack not empty
		else if (backtracker.cellStack.empty() == false) {
			// pop cell from stack and make it the current cell. Also set color to see when something comes
			// out of the stack
			mazeGrid[curCell.getPosX()][curCell.getPosY()].cellRect.setFillColor(OUT_OF_STACK);
			curCell.cellRect.setFillColor(OUT_OF_STACK);

			curCell = backtracker.cellStack.top();
			backtracker.cellStack.pop();
		}
		else {
			// to stop taking steps in the backtracker algorithm
			visited++;
		}
	}
}

void Grid::deleteWall(Cell* cell1, Cell* cell2) {
	// remember that you can only pass in two adjacent cells
	if (cell2->getPosX() == cell1->getPosX()) {
		if (cell2->getPosY() > cell1->getPosY() && cell2->wall == TOP_AND_LEFT) {
			std::cout << "delete 1" << std::endl;
			cell2->wall = LEFT;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
		}
		else if (cell2->getPosY() > cell1->getPosY() && cell2->wall == TOP) {
			std::cout << "delete 2" << std::endl;
			cell2->wall = NO_WALL;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
		}
		else if (cell2->getPosY() > cell1->getPosY() && cell2->wall == LEFT) {
			std::cout << "deletey" << std::endl;
			cell2->wall = LEFT;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
		}
		else if (cell1->getPosY() > cell2->getPosY() && cell1->wall == TOP_AND_LEFT) {
			std::cout << "delete a" << std::endl;
			cell1->wall = cell1->wall - 2;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
			mazeGrid[cell1->getPosX()][cell1->getPosY()] = *cell1;
		}
		else if (cell1->getPosY() > cell2->getPosY() && cell1->wall == TOP) {
			std::cout << "delete b" << std::endl;
			cell1->wall = NO_WALL;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
			mazeGrid[cell1->getPosX()][cell1->getPosY()] = *cell1;
		}
		else if (cell1->getPosY() > cell2->getPosY() && cell1->wall == LEFT) {
			std::cout << "dlety" << std::endl;
			cell1->wall = LEFT;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
			mazeGrid[cell1->getPosX()][cell1->getPosY()] = *cell1;
		}
	}

	else if (cell2->getPosY() == cell1->getPosY()) {
		if (cell2->getPosX() > cell1->getPosX() && cell2->wall == TOP_AND_LEFT) {
			std::cout << "delete 3" << std::endl;
			cell2->wall = TOP;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
		}
		else if (cell2->getPosX() > cell1->getPosX() && cell2->wall == LEFT) {
			std::cout << "delete 4" << std::endl;
			cell2->wall = NO_WALL;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
		}
		else if (cell2->getPosX() > cell1->getPosX() && cell2->wall == TOP) {
			std::cout << "delete 5" << std::endl;
			cell2->wall = TOP;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
		}
		else if (cell1->getPosX() > cell2->getPosX() && cell1->wall == TOP_AND_LEFT) {
			std::cout << "delete c" << std::endl;
			cell1->wall = TOP;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
			mazeGrid[cell1->getPosX()][cell1->getPosY()] = *cell1;
		}
		else if (cell1->getPosX() > cell2->getPosX() && cell1->wall == LEFT) {
			std::cout << "delete d" << std::endl;
			cell1->wall = NO_WALL;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
			mazeGrid[cell1->getPosX()][cell1->getPosY()] = *cell1;
		}
		else if (cell1->getPosX() > cell2->getPosX() && cell1->wall == TOP) {
			std::cout << "delete e" << std::endl;
			cell1->wall = TOP;
			cell2->visited = true;
			mazeGrid[cell2->getPosX()][cell2->getPosY()] = *cell2;
			mazeGrid[cell1->getPosX()][cell1->getPosY()] = *cell1;
		}
	}
}