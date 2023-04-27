#ifndef MAZE_H
#define MAZE_H
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Player.h"

class Maze
{
private:
	unsigned int mapWidth;
	unsigned int mapHeight;
	std::unique_ptr<bool[]> map;

public:
	Maze(unsigned int _mapWidth = MIN_MAP_SIZE, unsigned  int _mapHeight = MIN_MAP_SIZE);

	void draw(sf::RenderWindow& _window);
	bool mapAt(unsigned int x, unsigned int y);
	bool checkCollisions(Player& _player);
};

#endif
