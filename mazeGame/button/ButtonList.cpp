#include "ButtonList.h"

ButtonList::ButtonList(float _topButtonYPosition, const std::vector<std::string>& _textsOfButtons, const sf::Font& _font)
	: selectedOptionIndex(0)
{
	for (int i = 0; i < _textsOfButtons.size(); i++)
	{
		this->buttonList.emplace_back(Button(sf::Vector2f(float(SCREEN_WIDTH / 2), _topButtonYPosition + (BUTTON_HEIGHT + 1) * i), _textsOfButtons[i], _font));
	}
	this->buttonList.at(this->selectedOptionIndex).setIsSelected(true);
	//std::cout << "Button list initialized" << std::endl;
}

ButtonList::~ButtonList()
{
	//std::cout << "Button list destroyed" << std::endl;
}

void ButtonList::selectUp()
{
	this->buttonList.at(this->selectedOptionIndex).setIsSelected(false);
	this->selectedOptionIndex--;
	this->selectedOptionIndex += (this->selectedOptionIndex < 0) ? int(this->buttonList.size()) : 0;
	this->buttonList.at(this->selectedOptionIndex).setIsSelected(true);
}

void ButtonList::selectDown()
{
	this->buttonList.at(this->selectedOptionIndex).setIsSelected(false);
	this->selectedOptionIndex++;
	this->selectedOptionIndex -= (this->selectedOptionIndex >= int(this->buttonList.size())) ? int(this->buttonList.size()) : 0;
	this->buttonList.at(this->selectedOptionIndex).setIsSelected(true);
}

int ButtonList::getSelectedOptionIndex() const
{
	return this->selectedOptionIndex;
}

void ButtonList::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& button : this->buttonList)
		button.draw(target, states);
}
