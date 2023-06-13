#include "ButtonList.h"

ButtonList::ButtonList(float _topButtonYPosition, std::vector<std::string> _textsOfButtons)
	: selectedOptionIndex(0)
{
	for (int i = 0; i < _textsOfButtons.size(); i++)
	{
		this->buttonList.push_back(std::make_unique<Button>(sf::Vector2f(float(SCREEN_WIDTH / 2), _topButtonYPosition + (BUTTON_HEIGHT + 1) * i), _textsOfButtons[i]));
	}
	this->buttonList.at(this->selectedOptionIndex)->setIsSelected(true);
	std::cout << "Button list initialized" << std::endl;
}

ButtonList::~ButtonList()
{
	std::cout << "Button list destroyed" << std::endl;
}

void ButtonList::selectUp()
{
	this->buttonList.at(this->selectedOptionIndex)->setIsSelected(false);
	this->selectedOptionIndex--;
	this->selectedOptionIndex += (this->selectedOptionIndex < 0) ? int(this->buttonList.size()) : 0;
	this->buttonList.at(this->selectedOptionIndex)->setIsSelected(true);
}

void ButtonList::selectDown()
{
	this->buttonList.at(this->selectedOptionIndex)->setIsSelected(false);
	this->selectedOptionIndex++;
	this->selectedOptionIndex -= (this->selectedOptionIndex >= int(this->buttonList.size())) ? int(this->buttonList.size()) : 0;
	this->buttonList.at(this->selectedOptionIndex)->setIsSelected(true);
}

int ButtonList::getSelectedOptionIndex()
{
	return this->selectedOptionIndex;
}

void ButtonList::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& button : this->buttonList)
		button->draw(target, states);
}
