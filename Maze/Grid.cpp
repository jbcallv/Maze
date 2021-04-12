#include "Grid.h"

Grid::Grid(int rows, int cols) {
	// rows is always height / 50 (cellHeight)
	// cols is always width / 50 (cellWidth)
	this->rows = rows;
	this->cols = cols;
}

void Grid::Draw(sf::RenderWindow& window) {
	// iterate through cols first as col represents an x coordinate
	// and row represents a y coordinate
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			window.draw(mazeGrid.at(i).at(j).cellRect);
		}
	}
}

void Grid::generateCells() {
	for (int i = 0; i < cols; ++i) {
		std::vector<Cell> temp;
		temp.clear();
		for (int j = 0; j < rows; ++j) {
			temp.push_back(Cell(i, j));
		}
		mazeGrid.push_back(temp);
	}
}