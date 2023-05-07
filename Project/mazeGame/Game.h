#ifndef GAME_H
#define GAME_H
#pragma once

#include <SFML/Graphics.hpp>

#include "states/StateManager.h"
#include "states/GameState.h"
#include "states/MenuState.h"
#include "Maze.h"
#include "Player.h"
#include "Constants.h"

class Game
{
private:
	sf::RenderWindow window;
	StateManager stateManager;
public:
	void run();
};

#endif
