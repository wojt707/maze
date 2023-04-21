#include "Player.h"

Player::Player(sf::Vector2f _position, float _speed) :
	shape(sf::Vector2f(50.0f, 50.0f)), velocity(0.0f, 0.0f), speed(_speed)
{
	shape.setPosition(_position);
	shape.setFillColor(sf::Color::Green);
}

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x -= speed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x += speed;
	else if (velocity.x)
		velocity.x += (velocity.x > 0) ? -speed/2 : speed/2;



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		velocity.y -= speed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		velocity.y += speed;
	else if (velocity.y)
		velocity.y += (velocity.y > 0) ? -speed / 2 : speed / 2;
}

void Player::update(sf::Time _deltaTime)
{
	shape.move(velocity * _deltaTime.asSeconds());

	std::cout << velocity.x << ' ' << velocity.y << std::endl;
}

void Player::draw(sf::RenderWindow& _window)
{
	_window.draw(shape);
}
