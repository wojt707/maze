#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Player
{
private:
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	float speed;
public:
	Player(sf::Vector2f _position, float _speed);

	void handleInput();
	void update(sf::Time _deltaTime);
	void draw(sf::RenderWindow& _window);

};
#endif
