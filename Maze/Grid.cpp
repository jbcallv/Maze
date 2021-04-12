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
	int wallLoc;
	for (int i = 0; i <= cols; ++i) {
		for (int j = 0; j <= rows; ++j) {
			// get the location of the wall
			wallLoc = mazeGrid.at(i).at(j).wall;
			if (wallLoc == TOP_AND_LEFT) {
				// draw top and left walls
				window.draw(mazeGrid.at(i).at(j).leftWall);
				window.draw(mazeGrid.at(i).at(j).topWall);
				if (mazeGrid.at(i).at(j).visited) {
					mazeGrid.at(i).at(j).cellRect.setFillColor(VISITED);
					//window.draw(mazeGrid.at(i).at(j).cellRect);
				}
				window.draw(mazeGrid.at(i).at(j).cellRect);

			}
			else if (wallLoc == TOP) {
				// only draw top wall
				window.draw(mazeGrid.at(i).at(j).topWall);
				if (mazeGrid.at(i).at(j).visited) {
					mazeGrid.at(i).at(j).cellRect.setFillColor(VISITED);
				}
				window.draw(mazeGrid.at(i).at(j).cellRect);

			}
			else if (wallLoc == LEFT) {
				// only draw left wall
				window.draw(mazeGrid.at(i).at(j).leftWall);
				if (mazeGrid.at(i).at(j).visited) {
					mazeGrid.at(i).at(j).cellRect.setFillColor(VISITED);
				}
				window.draw(mazeGrid.at(i).at(j).cellRect);
			}
		}
	}
}

void Grid::generateCells() {
	for (int i = 0; i <= cols; ++i) {
		std::vector<Cell> temp;
		temp.clear();
		for (int j = 0; j <= rows; ++j) {
			// change last parameter to change wall location
			temp.push_back(Cell(i, j, 3));
		}
		mazeGrid.push_back(temp);
	}
}