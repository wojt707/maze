#include "GameOverState.h"


GameOverState::GameOverState(StateManager& _stateManager, sf::RenderWindow& _window)
	:State(_stateManager, _window),
	gameOverButtons(float(SCREEN_HEIGHT / 2), { "Restart", "Save and go to menu", "Quit" })
{
	std::cout << "GameOverState initialized" << std::endl;
}

GameOverState::~GameOverState()
{
	std::cout << "GameOverState destroyed" << std::endl;
}

void GameOverState::handleEnter()
{
	// all of this to rethink
	int selectedOption = this->gameOverButtons.getSelectedOptionIndex();
	switch (selectedOption)
	{
	case 0:
	{
		std::unique_ptr<State> gameState = std::make_unique<GameState>(this->stateManager, this->window);
		this->stateManager.popAllAndChange(std::move(gameState));
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

void GameOverState::handleInput()
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
				this->gameOverButtons.selectUp();
				break;
			case sf::Keyboard::Down:
				this->gameOverButtons.selectDown();
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

void GameOverState::update(sf::Time& _deltaTime)
{
}

void GameOverState::draw()
{

	this->window.clear(sf::Color::Black);

	sf::Font font;
	if (!font.loadFromFile("Fonts/PTC55F.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
	}
	sf::Text tempText("Game Over", font, 100);
	tempText.setFillColor(MAIN_COLOR);
	tempText.setOrigin(tempText.getGlobalBounds().width / 2, tempText.getGlobalBounds().height / 2);
	tempText.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

	this->window.draw(tempText);
	this->gameOverButtons.draw(this->window, sf::RenderStates::Default);

	this->window.display();
}
