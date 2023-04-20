#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Cell.h"
#include "Wall.h"

const unsigned int cellSideLength = 20;

class Maze
{
private:
	unsigned int rows;
	unsigned int cols;
	unsigned int screenWidth;
	unsigned int screenHeight;

	void createWalls();
	void shuffleWalls();

public:
	std::vector<std::vector<Cell>> cells;
	std::vector<Wall> walls;

	Maze(unsigned int _rows = 8, unsigned  int _cols = 8);
	void generate();
	void draw();
	void update();
};
