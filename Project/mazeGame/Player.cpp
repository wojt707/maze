#include "Player.h"

Player::Player(sf::Vector2f _position, float _displacementRate)
	: shape(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE)), displacement(0.0f, 0.0f), displacementRate(_displacementRate), angle(0.0f)
{
	shape.setOrigin(sf::Vector2f(PLAYER_SIZE / 2, PLAYER_SIZE / 2));
	shape.setPosition(_position);
	shape.setFillColor(sf::Color::Green);
}

sf::Vector2f Player::getPosition()
{
	return this->shape.getPosition();
}

sf::FloatRect Player::getGlobalBounds()
{
	return this->shape.getGlobalBounds();
}

void Player::setPosition(sf::Vector2f _position)
{
	this->shape.setPosition(_position);
}

void Player::setPosition(float x, float y)
{
	this->shape.setPosition(x, y);
}

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		angle += PLAYER_ROTATION_RATE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		angle -= PLAYER_ROTATION_RATE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		displacement.y = -displacementRate * sin(this->angle);
		displacement.x = displacementRate * cos(this->angle);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		displacement.y = displacementRate * sin(this->angle);
		displacement.x = -displacementRate * cos(this->angle);
	}
	else
	{
		displacement.x = 0.0f;
		displacement.y = 0.0f;
	}
}

void Player::update(sf::Time _deltaTime)
{
	this->angle = fmod(fmod(this->angle, 2 * PI) + 2 * PI, 2 * PI);

	shape.move(displacement * _deltaTime.asSeconds());
}

void Player::draw(sf::RenderWindow& _window)
{
	_window.draw(shape);
}
