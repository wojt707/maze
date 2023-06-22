#ifndef VIEW_HANDLER_H
#define VIEW_HANDLER_H
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Constants.h"

class ViewHandler
{
private:
	sf::View view;
	//float mapWidth;
	//float mapHeight;
public:
	ViewHandler(/*float _mapWidth, float _mapHeight*/);
	// Delete the copy constructor
	ViewHandler(const ViewHandler&) = delete;
	// Delete the copy assignment operator
	ViewHandler& operator=(const ViewHandler&) = delete;

	~ViewHandler();

	void updateRelativeTo(Player& _player, sf::Time& _deltaTime);
	void setViewAt(sf::RenderWindow& _window);
	void resetViewAt(sf::RenderWindow& _window);
};

#endif // !VIEW_HANDLER_H
