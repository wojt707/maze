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
	sf::Font font;
	bool isSelected;

public:
	Button(sf::Vector2f _buttonPosition, std::string _textOfButton = "");
	~Button();
	void setIsSelected(bool _isSelected);
	bool getIsSelected();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
