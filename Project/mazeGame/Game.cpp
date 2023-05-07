#include "Game.h"

void Game::run()
{
	this->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(120);

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
