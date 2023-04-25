#include "Game.h"
#include "Maze.h"
#include "Player.h"
#include "GameState.h"
#include "MenuState.h"

void Game::run()
{
	const unsigned int cols = 8;
	const unsigned int rows = 4;

	unsigned int screenWidth = (cols * 2 + 1) * cellSideLength;
	unsigned int screenHeight = (rows * 2 + 1) * cellSideLength;

	this->window.create(sf::VideoMode(screenWidth, screenHeight), "Maze");

	std::unique_ptr<State> menuState = std::make_unique<MenuState>(this->stateManager, this->window);
	this->stateManager.changeState(std::move(menuState));
		
	sf::Clock clock;

	while (this->stateManager.isRunning)
	{
		sf::Time deltaTime = clock.restart();
		this->stateManager.handleInput();
		this->stateManager.update(deltaTime);
		this->stateManager.draw();
	}

}
