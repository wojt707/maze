#pragma once
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Wall.h"

const unsigned int cellSideLength = 20;

class Maze
{
private:
	unsigned int rows;
	unsigned int cols;
	std::vector<std::vector<Cell>> cells;
	std::vector<Wall> walls;

	void createWalls();
	void shuffleWalls();
	void generate();
public:

	Maze(unsigned int _rows = 8, unsigned  int _cols = 8);
	void draw(sf::RenderWindow& _window);
};
