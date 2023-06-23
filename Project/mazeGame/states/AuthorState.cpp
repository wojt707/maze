#include "AuthorState.h"

AuthorState::AuthorState(GameData& _data)
	:State(_data),
	aboutAuthor("Student of Silesian University of Technology", *(this->data.resourceManager.fonts.get(FontIDs::MAIN_FONT).get()))
{
	this->aboutAuthor.setFillColor(sf::Color::White);
	this->aboutAuthor.setOrigin(this->aboutAuthor.getGlobalBounds().width / 2, this->aboutAuthor.getGlobalBounds().height / 2);
	this->aboutAuthor.setPosition(float(SCREEN_WIDTH / 2), float(SCREEN_HEIGHT / 4));

	std::cout << "AuthorState initialized" << std::endl;
}

AuthorState::~AuthorState()
{
	std::cout << "AuthorState destroyed" << std::endl;
}

void AuthorState::handleInput()
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

void AuthorState::update(sf::Time& _deltaTime)
{
}

void AuthorState::draw()
{
	this->data.window.clear(sf::Color::Black);

	this->data.window.draw(this->aboutAuthor);

	this->data.window.display();
}
