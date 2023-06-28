#include "ViewHandler.h"

ViewHandler::ViewHandler(/*float _mapWidth, float _mapHeight*/) :
	view(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT))
	/*,
	mapWidth(_mapWidth),
	mapHeight(_mapHeight)*/
{
	std::cout << "ViewHandler created" << std::endl;
}

ViewHandler::~ViewHandler()
{
	std::cout << "ViewHandler destroyed" << std::endl;
}

void ViewHandler::updateRelativeTo(Player& _player, sf::Time& _deltaTime)
{
	//auto left = this->view.getCenter().x - this->view.getSize().x / 2.f;
	//auto right = left + this->view.getSize().x;
	//auto top = this->view.getCenter().y - this->view.getSize().y / 2.f;
	//auto bottom = top + this->view.getSize().y;
	//std::cout << "left: " << left <<
	//	"right: " << right <<
	//	"top: " << top <<
	//	"bottom: " << bottom << std::endl;

	//left border of the view
	if (_player.getPosition().x < this->view.getCenter().x - this->view.getSize().x / 2.f + MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES) {
		this->view.move(_player.getDisplacement().x * _deltaTime.asSeconds(), 0);
	}
	//right border of the view
	else if (_player.getPosition().x > this->view.getCenter().x + this->view.getSize().x / 2.f - MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES) {
		this->view.move(_player.getDisplacement().x * _deltaTime.asSeconds(), 0);
	}
	//top border of the view
	if (_player.getPosition().y < this->view.getCenter().y - this->view.getSize().y / 2.f + MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES) {
		this->view.move(0, _player.getDisplacement().y * _deltaTime.asSeconds());
	}
	//bottom border of the view
	else if (_player.getPosition().y > this->view.getCenter().y + this->view.getSize().y / 2.f - MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES) {
		this->view.move(0, _player.getDisplacement().y * _deltaTime.asSeconds());
	}

	//if (_player.getPosition().x < left + MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES) {
	//	if (_player.getDisplacement().x < 0 && left > 0)
	//		view.move(_player.getDisplacement().x * _deltaTime.asSeconds(), 0);
	//}
	//else if (_player.getPosition().x > right - MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES) {
	//	if (_player.getDisplacement().x > 0 && right < this->mapWidth)
	//		view.move(_player.getDisplacement().x * _deltaTime.asSeconds(), 0);
	//}
	//if (_player.getPosition().y < top + MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES) {
	//	if (_player.getDisplacement().y < 0 && top > 0)
	//		view.move(0, _player.getDisplacement().y * _deltaTime.asSeconds());
	//}
	//else if (_player.getPosition().y > bottom - MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES) {
	//	if (_player.getDisplacement().y > 0 && bottom < this->mapHeight)
	//		view.move(0, _player.getDisplacement().y * _deltaTime.asSeconds());
	//}

}

void ViewHandler::setViewAt(sf::RenderWindow& _window)
{
	_window.setView(this->view);
}

void ViewHandler::resetViewAt(sf::RenderWindow& _window)
{
	this->view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	_window.setView(this->view);
}
