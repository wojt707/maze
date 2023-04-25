#ifndef GAME_H
#define GAME_H
#pragma once

#include <SFML/Graphics.hpp>

#include "StateManager.h"

class Game
{
private:
	sf::RenderWindow window;
	StateManager stateManager;
public:
	void run();
};

#endif
