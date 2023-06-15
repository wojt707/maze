#ifndef GAME_H
#define GAME_H
#pragma once

#include <SFML/Graphics.hpp>

#include "states/StateManager.h"
#include "states/MenuState.h"
#include "resources/ResourceManager.h"
#include "Constants.h"

class Game
{
private:
	sf::RenderWindow window;
	StateManager stateManager;
	ResourceManager resourceManager;
public:
	Game();
	void run();
};

#endif // !GAME_H
