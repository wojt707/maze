#include "MenuState.h"

MenuState::MenuState(GameData& _data)
	: State(_data),
	menuButtons(float(SCREEN_HEIGHT / 2), { "Play", "Load game save", "How to play", "Author", "Quit" }),
	menuText("Escape the maze", *(this->data.resourceManager.fonts.get(FontIDs::MAIN_FONT)), 100)
{
	this->menuText.setFillColor(MAIN_COLOR);
	this->menuText.setOrigin(this->menuText.getGlobalBounds().width / 2, this->menuText.getGlobalBounds().height / 2);
	this->menuText.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

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
		std::unique_ptr<State> gameState = std::make_unique<GameState>(this->data, 1);
		this->data.stateManager.changeState(std::move(gameState));
		return;
	}
	case 1:
		return;
	case 2:
		return;
	case 3:
		return;
	case 4:
		this->data.stateManager.quit();
		return;
	}
}

void MenuState::handleInput()
{
	sf::Event event;

	while (this->data.window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->data.stateManager.quit();
			return;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				this->data.stateManager.quit();
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
	this->data.window.clear(sf::Color::Black);

	this->data.window.draw(this->menuText);
	this->menuButtons.draw(this->data.window, sf::RenderStates::Default);

	this->data.window.display();
}
