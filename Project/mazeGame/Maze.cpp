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

void Maze::handleCollisions(Player& _player)
{
	int x = int(_player.getPosition().x / CELL_SIZE);
	int y = int(_player.getPosition().y / CELL_SIZE);

	sf::RectangleShape mapCell(sf::Vector2f(CELL_SIZE, CELL_SIZE));

	// top collision
	if (mapAt(x, y - 1))
	{
		mapCell.setPosition(float(CELL_SIZE * x), float(CELL_SIZE * (y - 1)));
		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds())) {
			std::cout << "top collision\n";
			_player.setPosition(_player.getPosition().x, y * CELL_SIZE + PLAYER_SIZE / 2);
		}
	}
	// left collision
	if (mapAt(x - 1, y))
	{
		mapCell.setPosition(float(CELL_SIZE * (x - 1)), float(CELL_SIZE * y));
		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds())) {
			std::cout << "left collision\n";
			_player.setPosition(x * CELL_SIZE + PLAYER_SIZE / 2, _player.getPosition().y);
		}
	}
	// right collision
	if (mapAt(x + 1, y))
	{
		mapCell.setPosition(float(CELL_SIZE * (x + 1)), float(CELL_SIZE * y));
		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds())) {
			std::cout << "right collision\n";
			_player.setPosition((x + 1) * CELL_SIZE - PLAYER_SIZE / 2, _player.getPosition().y);
		}
	}
	// down collision	
	if (mapAt(x, y + 1))
	{
		mapCell.setPosition(float(CELL_SIZE * x), float(CELL_SIZE * (y + 1)));
		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds())) {
			std::cout << "down collision\n";
			_player.setPosition(_player.getPosition().x, (y + 1) * CELL_SIZE - PLAYER_SIZE / 2);
		}
	}
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
