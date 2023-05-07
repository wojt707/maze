#include "PauseState.h"
#include "GameState.h"

PauseState::PauseState(StateManager& _stateManager, sf::RenderWindow& _window)
	: State(_stateManager, _window)
{
	std::cout << "PauseState initialized" << std::endl;
}

PauseState::~PauseState()
{
	std::cout << "PauseState destroyed" << std::endl;
}


void PauseState::handleInput()
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
				this->stateManager.popState();
				return;
			}
			break;
		default:
			break;
		}
	}
}

void PauseState::update(sf::Time& _deltaTime)
{

}

void PauseState::draw()
{

	this->window.clear(sf::Color::Black);

	sf::Font font;
	if (!font.loadFromFile("Fonts/PTC55F.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
	}
	sf::Text pauseText("Pause", font, 100);
	pauseText.setFillColor(sf::Color::Color(13, 100, 150));
	pauseText.setOrigin(pauseText.getGlobalBounds().width / 2, pauseText.getGlobalBounds().height / 2);
	pauseText.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

	this->window.draw(pauseText);

	this->window.display();
}
