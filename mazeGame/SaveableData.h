#ifndef SAVEABLE_DATA_H
#define SAVEABLE_DATA_H
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

struct SaveableData
{
	int level;
	bool isLevelCompleted;
	sf::Vector2f playerPosition;
	float playerAngle;
	//sf::Vector2f enemyCoordinates;
	unsigned int mapWidth;
	unsigned int mapHeight;
	std::shared_ptr<bool[]> map;
	//SaveableData(int _level,
	//	sf::Vector2f& _playerPosition,
	//	unsigned int _mapWidth,
	//	unsigned int _mapHeight,
	//	std::shared_ptr<bool[]> _map)
	//	: level(_level),
	//	playerPosition(_playerPosition),
	//	mapWidth(_mapWidth),
	//	mapHeight(_mapHeight),
	//	map(_map) { }

};

#endif // !SAVEABLE_DATA_H
