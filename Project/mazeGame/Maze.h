#ifndef MAZE_H
#define MAZE_H
#pragma once

#include <vector>
#include <random>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Wall.h"

const unsigned int cellSideLength = 80;

class Maze
{
private:
	unsigned int rows;
	unsigned int cols;
	unsigned int mapWidth;
	unsigned int mapHeight;
	std::vector<std::vector<Cell>> cells;
	std::vector<Wall> walls;
	std::unique_ptr<bool[]> map;

	void generate();
	void createWalls();
	void shuffleWalls();
	void createMap();
public:

	Maze(unsigned int _rows = 8, unsigned  int _cols = 8);
	void draw(sf::RenderWindow& _window);
	bool mapAt(unsigned int x, unsigned int y);
};

#endif
