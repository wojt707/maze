#include "Button.h"

Button::Button() : buttonShape(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE))
{
	this->buttonShape.setFillColor(sf::Color::Blue);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->buttonShape);
}
