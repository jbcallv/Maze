#include "Grid.h"

Grid::Grid(int rows, int cols) {
	// rows is always height / 50 (cellHeight)
	// cols is always width / 50 (cellWidth)
	this->rows = rows;
	this->cols = cols;
}

void Grid::Draw(sf::RenderWindow& window) {
	
}

void Grid::generateCells() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			Cell temp(i, j);
			//mazeGrid.at(i).at(j) = temp;
		}
	}
}