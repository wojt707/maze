#ifndef BUTTON_H
#define BUTTON_H
#pragma once

#include <SFML/Graphics.hpp>
#include "../Constants.h"


class Button: public sf::Drawable
{
private:
	//sf::Sprite button;
	sf::RectangleShape buttonShape;

public:
	Button();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
