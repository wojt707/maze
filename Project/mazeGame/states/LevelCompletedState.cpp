#include "LevelCompletedState.h"


LevelCompletedState::LevelCompletedState(StateManager& _stateManager, sf::RenderWindow& _window)
	:State(_stateManager, _window),
	levelCompletedButtons(float(SCREEN_HEIGHT / 2), { "Next level", "Save and go to menu", "Quit" })
{
	std::cout << "LevelCompletedState initialized" << std::endl;
}

LevelCompletedState::~LevelCompletedState()
{
	std::cout << "LevelCompletedState destroyed" << std::endl;
}

void LevelCompletedState::handleEnter()
{
	// all of this to rethink
	int selectedOption = this->levelCompletedButtons.getSelectedOptionIndex();
	switch (selectedOption)
	{
	case 0:
	{
		std::unique_ptr<State> nextGameState = std::make_unique<GameState>(this->stateManager, this->window);
		this->stateManager.popAllAndChange(std::move(nextGameState));
		return;
	}
	case 1:
	{
		std::unique_ptr<State> menuState = std::make_unique<MenuState>(this->stateManager, this->window);
		this->stateManager.popAllAndChange(std::move(menuState));
		return;
	}
	case 2:
		this->stateManager.quit();
		return;
	}
}

void LevelCompletedState::handleInput()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->stateManager.quit();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			//case sf::Keyboard::Escape:
			//	this->stateManager.popState();
			//	return;
			case sf::Keyboard::Up:
				this->levelCompletedButtons.selectUp();
				break;
			case sf::Keyboard::Down:
				this->levelCompletedButtons.selectDown();
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

void LevelCompletedState::update(sf::Time& _deltaTime)
{
}

void LevelCompletedState::draw()
{

	this->window.clear(sf::Color::Black);

	sf::Font font;
	if (!font.loadFromFile("Fonts/PTC55F.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
	}
	sf::Text tempText("Level completed", font, 100);
	tempText.setFillColor(MAIN_COLOR);
	tempText.setOrigin(tempText.getGlobalBounds().width / 2, tempText.getGlobalBounds().height / 2);
	tempText.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

	this->window.draw(tempText);
	this->levelCompletedButtons.draw(this->window, sf::RenderStates::Default);

	this->window.display();
}