#include "MenuState.h"

MenuState::MenuState(StateManager& _stateManager, sf::RenderWindow& _window)
	: State(_stateManager, _window),
	menuButtons(float(SCREEN_HEIGHT / 2), { "Play", "Load game save", "How to play", "Author", "Quit" })

{
	std::cout << "MenuState initialized" << std::endl;
}

MenuState::~MenuState()
{
	std::cout << "MenuState destroyed" << std::endl;
}

void MenuState::handleEnter()
{
	int selectedOption = this->menuButtons.getSelectedOptionIndex();
	switch (selectedOption)
	{
	case 0:
	{
		std::unique_ptr<State> gameState = std::make_unique<GameState>(this->stateManager, this->window);
		this->stateManager.changeState(std::move(gameState));
		return;
	}
	case 1:
		return;
	case 2:
		return;
	case 3:
		return;
	case 4:
		this->stateManager.quit();
		return;
	}
}

void MenuState::handleInput()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->stateManager.quit();
			return;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				this->stateManager.quit();
				return;
			case sf::Keyboard::Up:
				this->menuButtons.selectUp();
				break;
			case sf::Keyboard::Down:
				this->menuButtons.selectDown();
				break;
			case sf::Keyboard::Enter:
				this->handleEnter();
				return;
			default:
				break;
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
	this->menuButtons.draw(this->window, sf::RenderStates::Default);

	this->window.display();
}
