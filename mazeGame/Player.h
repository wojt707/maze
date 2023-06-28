#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>

#include "Constants.h"

class Player
{
private:
	sf::RectangleShape shape;
	sf::Vector2f displacement;
	float displacementRate;
	float angle; // in radians
public:
	Player(sf::Vector2f _position, float _initialAngle, float _displacementRate = 200.0f);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _position);
	void setPosition(float x, float y);
	
	sf::Vector2f getOrigin();
	sf::Vector2f getDisplacement();
	float getAngle();
	sf::FloatRect getGlobalBounds();

	void handleInput();
	void update(sf::Time& _deltaTime);
	void draw(sf::RenderWindow& _window);

};

#endif // !PLAYER_H
