#ifndef GAME_DATA_H
#define GAME_DATA_H
#pragma once

#include <SFML/Graphics.hpp>

#include "states/StateManager.h"
#include "resources/ResourceManager.h"
#include "SaveManager.h"

// based on SOLID open/closed principle I decided to group data which will be shared among all states
// so I can add needed data without modifying existing code
class GameData
{
public:
	StateManager stateManager;
	ResourceManager resourceManager;
	SaveManager saveManager;
	sf::RenderWindow window;
};

#endif // !GAME_DATA_H
