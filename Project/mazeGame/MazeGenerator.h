#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H
#pragma once

#include <vector>
#include <random>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Wall.h"
#include "Player.h"

class MazeGenerator
{
private:
	unsigned int rows;
	unsigned int cols;
	unsigned int mapWidth;
	unsigned int mapHeight;
	std::vector<std::vector<Cell>> cells;
	std::vector<Wall> walls;

	void generate();
	void createWalls();
	void shuffleWalls();
public:
	MazeGenerator(unsigned  int _cols = 8, unsigned int _rows = 8);
	std::unique_ptr<bool[]> createMap();
};

#endif
