#include "MenuState.h"

MenuState::MenuState(GameData& _data)
	: State(_data),
	menuButtons(float(SCREEN_HEIGHT / 2), MENU_OPTIONS, this->data.resourceManager.fonts.get(FontIDs::MAIN_FONT)),
	menuText("Escape the maze", this->data.resourceManager.fonts.get(FontIDs::MAIN_FONT), 100)
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
	{
		try
		{
			// TODO implement user input to get file name
			std::string fileName = "default_5.txt";

			auto dataFromFile = this->data.saveManager.loadFromFile(fileName);

			std::unique_ptr<State> gameState = std::make_unique<GameState>(this->data, dataFromFile);
			this->data.stateManager.changeState(std::move(gameState));
			return;
		}
		catch (const std::exception& e)
		{
			std::cout << std::endl << "EXCEPTION: " << e.what() << std::endl;
			break;
		}
	}
	case 2:
	{
		std::unique_ptr<State> howToPlayState = std::make_unique<HowToPlayState>(this->data);
		this->data.stateManager.pushState(std::move(howToPlayState));
		return;
	}
	case 3:
	{
		std::unique_ptr<State> authorState = std::make_unique<AuthorState>(this->data);
		this->data.stateManager.pushState(std::move(authorState));
		return;
	}
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
