#include "Button.h"

Button::Button(sf::Vector2f _buttonPosition, const std::string& _textOfButton, const sf::Font& _font)
	: buttonShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT)),
	textOfButton(_textOfButton, _font),
	isSelected(false)
{
	this->buttonShape.setOrigin(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2);
	this->buttonShape.setPosition(_buttonPosition);
	//this->buttonShape.setOutlineColor(MAIN_COLOR);
	this->buttonShape.setFillColor(sf::Color::Transparent);
	//this->buttonShape.setOutlineThickness(1.0);

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

bool Button::getIsSelected() const
{
	return this->isSelected;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->buttonShape);
	target.draw(this->textOfButton);
}
