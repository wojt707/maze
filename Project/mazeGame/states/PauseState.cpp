#include "PauseState.h"

PauseState::PauseState(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window)
	: State(_stateManager, _resourceManager, _window),
	pauseStateButtons(float(SCREEN_HEIGHT / 2), { "Resume", "Save and go to menu", "How to play", "Quit" }),
	pauseStateText("Pause", *(this->resourceManager.fonts.get(FontIDs::MAIN_FONT).get()), 100)
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
		this->stateManager.popState();
		return;
	case 1:
	{
		std::unique_ptr<State> menuState = std::make_unique<MenuState>(this->stateManager, this->resourceManager, this->window);
		this->stateManager.popAllAndChange(std::move(menuState));
		return;
	}
	case 2:
		return;
	case 3:
		this->stateManager.quit();
		return;
	}
}

void PauseState::handleInput()
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
			case sf::Keyboard::Escape:
				this->stateManager.popState();
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

	this->window.clear(sf::Color::Black);

	this->window.draw(this->pauseStateText);
	this->pauseStateButtons.draw(this->window, sf::RenderStates::Default);

	this->window.display();
}
