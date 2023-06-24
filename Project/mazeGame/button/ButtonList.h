#ifndef BUTTON_LIST_H
#define BUTTON_LIST_H
#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
 
#include "../Constants.h"
#include "Button.h"

class ButtonList : public sf::Drawable
{
private:
	std::vector<Button> buttonList;
	int selectedOptionIndex;

public:
	ButtonList(float _topButtonYPosition, const std::vector<std::string>& _textsOfButtons, const sf::Font& _font);
	~ButtonList();

	void selectUp();
	void selectDown();
	int getSelectedOptionIndex() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
