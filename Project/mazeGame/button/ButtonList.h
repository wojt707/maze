#ifndef BUTTON_LIST_H
#define BUTTON_LIST_H
#pragma once

#include <vector>
#include <iostream>
#include "Button.h"

class ButtonList : public sf::Drawable
{
private:
	std::vector<std::unique_ptr<Button>> buttonList;
	int selectedOptionIndex;

public:
	ButtonList(float _topButtonYPosition, std::vector<std::string> _textsOfButtons);
	~ButtonList();

	void selectUp();
	void selectDown();
	int getSelectedOptionIndex();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
