#include "GameState.h"

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
		case sf::Event::LostFocus:
		{
			std::unique_ptr<State> pauseState = std::make_unique<PauseState>(this->stateManager, this->window);
			this->stateManager.pushState(std::move(pauseState));
			return;
		}
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				std::unique_ptr<State> pauseState = std::make_unique<PauseState>(this->stateManager, this->window);
				this->stateManager.pushState(std::move(pauseState));
				return;
			}
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
