#include "Grid.h"

Grid::Grid(int rows, int cols, int seed) {
	// rows is always height / 50 (cellHeight)
	// cols is always width / 50 (cellWidth)
	this->rows = rows;
	this->cols = cols;
	this->seed = seed;

	// make this entire class more efficient by using a 1D array instead
	this->mazeGrid = new Cell*[cols];
	for (int i = 0; i < cols; ++i) {
		mazeGrid[i] = new Cell[rows];
	}
	//std::cout << rows << ", " << cols << std::endl;
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
	// change all vector stuff to an array
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
	int visited = 1;
	if (visited < (rows * cols)) {
		// delete test
		//Cell cellly = mazeGrid[curCell.getPosX() - 1][curCell.getPosY()];
		//backtracker.deleteWall(mazeGrid, curCell, cellly);

		// find adjacent test

		// curCell has adjacent unvisited cell
		// bug here. It's not finding the adjacent cells :[
		if (backtracker.findAdjacentCells(mazeGrid, curCell).size() > 0) {
			// push current cell to stack
			backtracker.cellStack.push(curCell);
			// generate a random adjacent cell
			Cell chosenCell = backtracker.generateRandomAdjacentCell(curCell, mazeGrid);
			std::cout << "cur Cell: " << curCell.getPosX() << ", " << curCell.getPosY() << std::endl;
			std::cout << "chosen cell: " << chosenCell.getPosX() << ", " << chosenCell.getPosY() << std::endl;
			// remove wall between curCell and chosen cell

			// passing by value here which doesn't modify cell 1 or cell 2
			// prove that my speculation is correct by printing out cell2.wall and cell1.wall here
			// TODO: change all cells into pointers and all vectors into arrays
			// TODO: change to ampersand before backtracker
			backtracker.deleteWall(mazeGrid, curCell, chosenCell);

			// make chosen cell the curCell and mark it as visited
			//curCell.visited = true;
			chosenCell.visited = true;
			curCell = chosenCell;
			// increment num of cells visited
			visited++;
		}
		// else if stack not empty
		else if (backtracker.cellStack.empty() == false) {
			std::cout << "in else if" << std::endl;
			// pop cell from stack and make it the current cell
			// commented next line as it gets set as visited in next step
			//backtracker.cellStack.top().visited = true;
			//curCell.cellRect.setFillColor(sf::Color::Green);
			std::cout << "Before: " << curCell.cellRect.getFillColor().toInteger() << std::endl;
			mazeGrid[curCell.getPosX()][curCell.getPosY()].cellRect.setFillColor(OUT_OF_STACK);
			curCell.cellRect.setFillColor(OUT_OF_STACK);
			std::cout << "After: " << curCell.cellRect.getFillColor().toInteger() << std::endl;
			curCell = backtracker.cellStack.top();
			//mazeGrid[curCell.getPosX()][curCell.getPosY()] = curCell;
			//mazeGrid[curCell.getPosX()][curCell.getPosY()].cellRect.setFillColor(sf::Color::Red);// = curCell;
			backtracker.cellStack.pop();
			// increment num of cells visited
			//visited++;
		}
	}
}