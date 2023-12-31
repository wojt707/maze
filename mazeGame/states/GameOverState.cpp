#include "GameOverState.h"

GameOverState::GameOverState(GameData& _data)
	:State(_data),
	gameOverButtons(float(SCREEN_HEIGHT / 2), GAME_OVER_OPTIONS, this->data.resourceManager.fonts.get(FontIDs::MAIN_FONT)),
	gameOverText("Game over", this->data.resourceManager.fonts.get(FontIDs::MAIN_FONT), 100)
{
	this->gameOverText.setFillColor(MAIN_COLOR);
	this->gameOverText.setOrigin(this->gameOverText.getGlobalBounds().width / 2, this->gameOverText.getGlobalBounds().height / 2);
	this->gameOverText.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

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
		std::unique_ptr<State> gameState = std::make_unique<GameState>(this->data, 1);
		this->data.stateManager.popAllAndChange(std::move(gameState));
		return;
	}
	case 1:
	{
		std::unique_ptr<State> menuState = std::make_unique<MenuState>(this->data);
		this->data.stateManager.popAllAndChange(std::move(menuState));
		return;
	}
	case 2:
		this->data.stateManager.quit();
		return;
	}
}

void GameOverState::handleInput()
{
	sf::Event event;

	while (this->data.window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->data.stateManager.quit();
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
	this->data.window.clear(sf::Color::Black);

	this->data.window.draw(this->gameOverText);
	this->gameOverButtons.draw(this->data.window, sf::RenderStates::Default);

	this->data.window.display();
}
