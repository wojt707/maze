#include "HowToPlayState.h"

HowToPlayState::HowToPlayState(GameData& _data)
	:State(_data),
	description("W and S to move forth and back\n<- and -> to rotate", *(this->data.resourceManager.fonts.get(FontIDs::MAIN_FONT).get()))
{
	this->description.setFillColor(sf::Color::White);
	this->description.setOrigin(this->description.getGlobalBounds().width / 2, this->description.getGlobalBounds().height / 2);
	this->description.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

	std::cout << "HowToPlayState initialized" << std::endl;
}

HowToPlayState::~HowToPlayState()
{
	std::cout << "HowToPlayState destroyed" << std::endl;
}

void HowToPlayState::handleInput()
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
				this->data.stateManager.popState();
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

void HowToPlayState::update(sf::Time& _deltaTime)
{
}

void HowToPlayState::draw()
{
	this->data.window.clear(sf::Color::Black);

	this->data.window.draw(this->description);

	this->data.window.display();
}
