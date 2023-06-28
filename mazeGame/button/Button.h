#ifndef BUTTON_H
#define BUTTON_H
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Constants.h"


class Button : public sf::Drawable
{
private:
	sf::RectangleShape buttonShape;
	sf::Text textOfButton;
	bool isSelected;

public:
	Button(sf::Vector2f _buttonPosition, const std::string& _textOfButton, const sf::Font& _font);
	~Button();

	void setIsSelected(bool _isSelected);
	bool getIsSelected() const;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
