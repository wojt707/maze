#include "Maze.h"
#include "MazeGenerator.h"

Maze::Maze(unsigned int _mapWidth, unsigned int _mapHeight)
	: map(nullptr)
{
	// Making sure that width and height of the map are odd numbers not less than 9
	this->mapWidth = (_mapWidth < MIN_MAP_SIZE) ? MIN_MAP_SIZE : _mapWidth;
	this->mapHeight = (_mapHeight < MIN_MAP_SIZE) ? MIN_MAP_SIZE : _mapHeight;
	this->mapWidth += (this->mapWidth % 2) ? 0 : 1;
	this->mapHeight += (this->mapHeight % 2) ? 0 : 1;

	MazeGenerator mazeGenerator((this->mapWidth - 1) / 2, (this->mapHeight - 1) / 2);
	this->map = mazeGenerator.createMap();
}

bool Maze::mapAt(unsigned int x, unsigned int y)
{
	return this->map[y * this->mapWidth + x];
}

bool Maze::checkCollisions(Player& _player)
{
	//bool collided = false;
	int x = int(_player.getPosition().x / CELL_SIZE);
	int y = int(_player.getPosition().y / CELL_SIZE);

	//std::cout << "x: " << x << ", y: " << y << std::endl;

	sf::RectangleShape mapCell(sf::Vector2f(CELL_SIZE, CELL_SIZE));

	if (mapAt(x - 1, y))
	{
		std::cout << "left" << std::endl;
		mapCell.setPosition(float(CELL_SIZE * (x - 1)), float(CELL_SIZE * y));
		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds())) {
			return true;
		}
	}
	if (mapAt(x + 1, y))
	{
		std::cout << "right" << std::endl;
		mapCell.setPosition(float(CELL_SIZE * (x + 1)), float(CELL_SIZE * y));
		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds())) {
			return true;
		}
	}
	if (mapAt(x, y - 1))
	{
		std::cout << "up" << std::endl;
		mapCell.setPosition(float(CELL_SIZE * x), float(CELL_SIZE * (y - 1)));
		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds())) {
			return true;
		}
	}
	if (mapAt(x, y + 1))
	{
		std::cout << "down" << std::endl;
		mapCell.setPosition(float(CELL_SIZE * x), float(CELL_SIZE * (y + 1)));
		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds())) {
			return true;
		}
	}

	return false;
}

void Maze::draw(sf::RenderWindow& _window)
{
	sf::RectangleShape mapCell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	mapCell.setFillColor(sf::Color::White);

	for (unsigned int y = 0; y < this->mapHeight; y++)
	{
		for (unsigned int x = 0; x < this->mapWidth; x++)
		{
			if (!this->mapAt(x, y)) // if the map at (x,y) is true then there is a wall, if false then there is a path
			{
				mapCell.setPosition(float(CELL_SIZE * x), float(CELL_SIZE * y));
				_window.draw(mapCell);
			}
		}
	}
}
