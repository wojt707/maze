#include "Button.h"

Button::Button(sf::Vector2f _buttonPosition, std::string _textOfButton)
	: buttonShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT)),
	isSelected(false)
{
	if (!this->font.loadFromFile("Fonts/PTC55F.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
		std::exit(1);
	}
	this->buttonShape.setOrigin(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2);
	this->buttonShape.setPosition(_buttonPosition);
	this->buttonShape.setOutlineColor(MAIN_COLOR);
	this->buttonShape.setFillColor(sf::Color::Transparent);
	this->buttonShape.setOutlineThickness(1.0);

	this->textOfButton.setString(_textOfButton);
	this->textOfButton.setFont(this->font);
	this->textOfButton.setOrigin(this->textOfButton.getGlobalBounds().width / 2, this->textOfButton.getGlobalBounds().height / 2);
	this->textOfButton.setPosition(_buttonPosition);
	this->textOfButton.setFillColor(MAIN_COLOR);

	//std::cout << "Button initialized" << std::endl;
}

Button::~Button()
{
	//std::cout << "Button destroyed" << std::endl;
}

void Button::setIsSelected(bool _isSelected)
{
	this->isSelected = _isSelected;
	if (_isSelected)
	{
		this->buttonShape.setFillColor(MAIN_COLOR);
		this->textOfButton.setFillColor(sf::Color::White);
	}
	else
	{
		this->buttonShape.setFillColor(sf::Color::Transparent);
		this->textOfButton.setFillColor(MAIN_COLOR);
	}
}

bool Button::getIsSelected()
{
	return this->isSelected;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->buttonShape);
	target.draw(this->textOfButton);
}
