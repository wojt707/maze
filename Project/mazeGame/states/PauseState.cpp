#include "PauseState.h"

PauseState::PauseState(GameData& _data, std::shared_ptr<SaveableData> _saveableData)
	: State(_data),
	pauseStateButtons(float(SCREEN_HEIGHT / 2), { "Resume", "Save and go to menu", "How to play", "Quit" }),
	pauseStateText("Pause", *(this->data.resourceManager.fonts.get(FontIDs::MAIN_FONT)), 100),
	saveableData(_saveableData)
{
	this->pauseStateText.setFillColor(MAIN_COLOR);
	this->pauseStateText.setOrigin(this->pauseStateText.getGlobalBounds().width / 2, this->pauseStateText.getGlobalBounds().height / 2);
	this->pauseStateText.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

	std::cout << "PauseState initialized" << std::endl;
}

PauseState::~PauseState()
{
	std::cout << "PauseState destroyed" << std::endl;
}

void PauseState::handleEnter()
{
	int selectedOption = this->pauseStateButtons.getSelectedOptionIndex();
	switch (selectedOption)
	{
	case 0:
		this->data.stateManager.popState();
		return;
	case 1:
	{
		this->data.saveManager.saveToFile(this->saveableData);
		std::unique_ptr<State> menuState = std::make_unique<MenuState>(this->data);
		this->data.stateManager.popAllAndChange(std::move(menuState));
		return;
	}
	case 2:
		return;
	case 3:
		this->data.stateManager.quit();
		return;
	}
}

void PauseState::handleInput()
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
			case sf::Keyboard::Escape:
				this->data.stateManager.popState();
				return;
			case sf::Keyboard::Up:
				this->pauseStateButtons.selectUp();
				break;
			case sf::Keyboard::Down:
				this->pauseStateButtons.selectDown();
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

void PauseState::update(sf::Time& _deltaTime)
{

}

void PauseState::draw()
{

	this->data.window.clear(sf::Color::Black);

	this->data.window.draw(this->pauseStateText);
	this->pauseStateButtons.draw(this->data.window, sf::RenderStates::Default);

	this->data.window.display();
}
