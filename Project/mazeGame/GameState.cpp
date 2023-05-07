#include "GameState.h"
#include "Constants.h"

GameState::GameState(StateManager& _stateManager, sf::RenderWindow& _window)
	: State(_stateManager, _window),
	maze(15, 9),
	player(sf::Vector2f(CELL_SIZE * 1.5f, CELL_SIZE * 1.5f), 100.0f)
{
	std::cout << "GameState initialized" << std::endl;
}

GameState::~GameState()
{
	std::cout << "GameState destroyed" << std::endl;
}

void GameState::handleInput()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			this->stateManager.quit();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				this->stateManager.quit();
			break;
		default:
			break;
		}
	}
	this->player.handleInput();
}

void GameState::update(sf::Time& _deltaTime)
{
	this->player.update(_deltaTime);

	this->maze.handleCollisions(this->player);
}

void GameState::draw()
{
	this->window.clear(sf::Color::Black);

	this->maze.draw(this->window);
	this->player.draw(this->window);

	this->window.display();
}
