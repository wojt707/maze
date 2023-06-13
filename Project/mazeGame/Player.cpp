#include "Player.h"

Player::Player(sf::Vector2f _position, float _displacementRate)
	: shape(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE)),
	displacement(0.0f, 0.0f),
	displacementRate(_displacementRate),
	angle(0.0f)
{
	this->shape.setOrigin(sf::Vector2f(PLAYER_SIZE / 2, PLAYER_SIZE / 2));
	this->shape.setPosition(_position);
	this->shape.setFillColor(sf::Color::Green);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->angle += PLAYER_ROTATION_RATE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->angle -= PLAYER_ROTATION_RATE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->displacement.x = this->displacementRate * cos(this->angle);
		this->displacement.y = -this->displacementRate * sin(this->angle);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->displacement.x = -this->displacementRate * cos(this->angle);
		this->displacement.y = this->displacementRate * sin(this->angle);
	}
	else
	{
		this->displacement.x = 0.0f;
		this->displacement.y = 0.0f;
	}
}

void Player::update(sf::Time _deltaTime)
{
	this->angle = fmod(fmod(this->angle, TWO_PI) + TWO_PI, TWO_PI);

	shape.move(displacement * _deltaTime.asSeconds());
}

void Player::draw(sf::RenderWindow& _window)
{

	_window.draw(this->shape);



	sf::VertexArray line(sf::Lines, 2);
	line[0] = sf::Vertex(this->getPosition());
	line[1] = sf::Vertex(this->getPosition() + sf::Vector2f(50.0f * cos(this->angle), -50.0f * sin(this->angle)));
	line[0].color = sf::Color::Cyan;
	line[1].color = sf::Color::Magenta;
	_window.draw(line);
}
