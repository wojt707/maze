#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H
#pragma once

#include <vector>
#include <random>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Wall.h"

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
	MazeGenerator(unsigned  int _mapWidth, unsigned int _mapHeight);
	// TODO (maybe)
	// Delete the copy constructor
	//MazeGenerator(const MazeGenerator&) = delete;
	// Delete the copy assignment operator
	//MazeGenerator& operator=(const MazeGenerator&) = delete;

	std::unique_ptr<bool[]> createMap();
};

#endif // !MAZE_GENERATOR_H
