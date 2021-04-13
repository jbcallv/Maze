#pragma once
#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include "Constants.h"

class Cell {
public:

	/*
	stores which side of the cell 
	has a wall. Change this int as walls are
	deleted
	*/
	int wall;

	/*
	holds wheter the cell
	has been visited
	*/
	bool visited;

	/*
	default constructor for the curCell
	in Grid.cpp
	*/
	Cell();

	/*
	constructor to make a cell
	at row x and column y, with a wall on side
	walls
	*/
	Cell(int x, int y, int walls);

	/*
	sets the cell walls depending on parameter
	*/
	void generateWalls();

	/*
	getter for x
	*/
	int getPosX();

	/*
	getter for y
	*/
	int getPosY();

	/*
	the cell rectangle
	*/
	// removed as we only need walls - sf::RectangleShape cellRect;
	sf::RectangleShape cellRect;

	// walls for each cell
	sf::RectangleShape topWall;
	sf::RectangleShape leftWall;

private:
	// row and column
	int x;
	int y;

	int cellWidth = CELL_WIDTH;
	int cellHeight = CELL_HEIGHT;
};
#endif
