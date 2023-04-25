#include "MenuState.h"
#include "GameState.h"

MenuState::MenuState(StateManager& _stateManager, sf::RenderWindow& _window)
	: State(_stateManager, _window)
{
	std::cout << "MenuState initialized" << std::endl;
}

MenuState::~MenuState()
{
	std::cout << "MenuState destroyed" << std::endl;
}


void MenuState::handleInput()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			this->stateManager.quit();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				this->stateManager.quit();
				return;
			case sf::Keyboard::Enter:
				std::unique_ptr<State> gameState = std::make_unique<GameState>(this->stateManager, this->window);
				this->stateManager.changeState(std::move(gameState));
				return;
			}
			break;
		default:
			break;
		}
	}
}

void MenuState::update(sf::Time& _deltaTime)
{

}

void MenuState::draw()
{

	this->window.clear(sf::Color::Black);

	sf::RectangleShape rec(sf::Vector2f(20.0f, 20.0f));
	rec.setFillColor(sf::Color::Red);
	this->window.draw(rec);

	this->window.display();
}
