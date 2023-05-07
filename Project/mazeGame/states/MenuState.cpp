#include "MenuState.h"

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

	sf::Font font;
	if (!font.loadFromFile("Fonts/PTC55F.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
	}
	sf::Text pauseText("Escape the maze", font, 100);
	pauseText.setFillColor(sf::Color::Color(13, 100, 150));
	pauseText.setOrigin(pauseText.getGlobalBounds().width / 2, pauseText.getGlobalBounds().height / 2);
	pauseText.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

	this->window.draw(pauseText);

	this->window.display();
}
