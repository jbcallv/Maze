#include "Grid.h"

Grid::Grid(int rows, int cols, int seed) {
	// rows is always height / 50 (cellHeight)
	// cols is always width / 50 (cellWidth)
	this->rows = rows;
	this->cols = cols;
	this->seed = seed;

	this->mazeGrid = new Cell*[cols];
	for (int i = 0; i < rows; ++i) {
		mazeGrid[i] = new Cell[rows];
	}
}

void Grid::Draw(sf::RenderWindow& window) {
	// iterate through cols first as col represents an x coordinate
	// and row represents a y coordinate
	int wallLoc;
	for (int i = 0; i <= cols; ++i) {
		for (int j = 0; j <= rows; ++j) {
			// get the location of the wall
			//wallLoc = mazeGrid.at(i).at(j).wall;
			wallLoc = mazeGrid[i][j].wall;
			if (wallLoc == TOP_AND_LEFT) {
				// draw top and left walls
				//window.draw(mazeGrid.at(i).at(j).leftWall);
				window.draw(mazeGrid[i][j].leftWall);
				//window.draw(mazeGrid.at(i).at(j).topWall);
				window.draw(mazeGrid[i][j].topWall);
				//if (mazeGrid.at(i).at(j).visited) {
				if (mazeGrid[i][j].visited) {
					//mazeGrid.at(i).at(j).cellRect.setFillColor(VISITED);
					mazeGrid[i][j].cellRect.setFillColor(VISITED);
				}
				//window.draw(mazeGrid.at(i).at(j).cellRect);
				window.draw(mazeGrid[i][j].cellRect);
			}
			else if (wallLoc == TOP) {
				// only draw top wall
				//window.draw(mazeGrid.at(i).at(j).topWall);
				window.draw(mazeGrid[i][j].topWall);
				//if (mazeGrid.at(i).at(j).visited) {
				if (mazeGrid[i][j].visited) {
					//mazeGrid.at(i).at(j).cellRect.setFillColor(VISITED);
					mazeGrid[i][j].cellRect.setFillColor(VISITED);
				}
				//window.draw(mazeGrid.at(i).at(j).cellRect);
				window.draw(mazeGrid[i][j].cellRect);
			}
			else if (wallLoc == LEFT) {
				// only draw left wall
				//window.draw(mazeGrid.at(i).at(j).leftWall);
				window.draw(mazeGrid[i][j].leftWall);
				//if (mazeGrid.at(i).at(j).visited) {
				if (mazeGrid[i][j].visited) {
					//mazeGrid.at(i).at(j).cellRect.setFillColor(VISITED);
					mazeGrid[i][j].cellRect.setFillColor(VISITED);
				}
				//window.draw(mazeGrid.at(i).at(j).cellRect);
				window.draw(mazeGrid[i][j].cellRect);
			}

			else if (wallLoc == NO_WALL) {
				// draw no wall
				//if (mazeGrid.at(i).at(j).visited) {
				if (mazeGrid[i][j].visited) {
					//mazeGrid.at(i).at(j).cellRect.setFillColor(VISITED);
					mazeGrid[i][j].cellRect.setFillColor(VISITED);
				}
				//window.draw(mazeGrid.at(i).at(j).cellRect);
				window.draw(mazeGrid[i][j].cellRect);
			}
		}
	}
}

void Grid::generateCells() {
	// change all vector stuff to an array
	for (int i = 0; i <= cols; ++i) {
		Cell temp[HEIGHT / CELL_HEIGHT];// = new int[rows];
		//std::vector<Cell> temp;
		//temp.clear();
		for (int j = 0; j <= rows; ++j) {
			// change last parameter to change wall location
			// make each cell a pointer
			temp[j] = Cell(i, j, 3);
			//temp.push_back(Cell(i, j, 3));
		}
		//mazeGrid.push_back(temp);
		mazeGrid[i] = temp;
	}
	sf::Vector2f startingPoint = generateStartingCellBacktracker();
	//mazeGrid.at(startingPoint.x).at(startingPoint.y).visited = true;
	mazeGrid[(int) startingPoint.x][(int) startingPoint.y].visited = true;
	//curCell = mazeGrid.at(startingPoint.x).at(startingPoint.y);
	curCell = mazeGrid[(int)startingPoint.x][(int)startingPoint.y];
	std::cout << curCell.getPosX() << ", " << curCell.getPosY() << std::endl;
}

sf::Vector2f Grid::generateStartingCellBacktracker() {
	//srand(seed);

	// x is cols and y is rows
	int x = rand() % cols;
	int y = rand() % rows;

	return (sf::Vector2f(x, y));
}

void Grid::stepBacktracker() {
	// takes one step in the backtracker algorithm
	int visited = 1;
	if (visited < (rows * cols)) {
		std::cout << "in" << std::endl;
		// curCell has adjacent unvisited cell
		if (backtracker.findAdjacentCells(mazeGrid, curCell).size() > 0) {
			std::cout << "in if" << std::endl;
			// push current cell to stack
			backtracker.cellStack.push(curCell);
			// generate a random adjacent cell
			Cell chosenCell = backtracker.generateRandomAdjacentCell(curCell, mazeGrid);
			// remove wall between curCell and chosen cell

			// passing by value here which doesn't modify cell 1 or cell 2
			// prove that my speculation is correct by printing out cell2.wall and cell1.wall here
			// TODO: change all cells into pointers and all vectors into arrays
			// TODO: change to ampersand before backtracker
			backtracker.deleteWall(backtracker.findLeftOrAbove(curCell, chosenCell), backtracker.findRightOrBelow(curCell, chosenCell));

			// make chosen cell the curCell and mark it as visited
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
			curCell = backtracker.cellStack.top();
			backtracker.cellStack.pop();
			// increment num of cells visited
			//visited++;
		}
	}
}