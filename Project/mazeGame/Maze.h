#ifndef MAZE_H
#define MAZE_H
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "mazeGenerator/MazeGenerator.h"
#include "Constants.h"
#include "Player.h"

class Maze
{
private:
	unsigned int mapWidth;
	unsigned int mapHeight;
	std::shared_ptr<bool[]> map;

	sf::RectangleShape mapCell;
	sf::Vector2f startingCellPosition;
	sf::Vector2f endingCellPosition;

	bool mapAt(unsigned int x, unsigned int y);

public:
	Maze(unsigned int _mapWidth = MIN_MAP_SIZE, unsigned  int _mapHeight = MIN_MAP_SIZE);
	// TODO rethink if delete it or not	

	// Delete the copy constructor
	Maze(const Maze&) = delete;
	// Delete the copy assignment operator
	Maze& operator=(const Maze&) = delete;

	unsigned int getMapWidth();
	unsigned int getMapHeight();
	std::shared_ptr<bool[]> getMap();

	bool isLevelFinished(Player& _player);
	void handleCollisions(Player& _player);
	void draw(sf::RenderWindow& _window);
};

#endif // !MAZE_H
