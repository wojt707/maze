#include "Maze.h"

Maze::Maze(unsigned int _mapWidth, unsigned int _mapHeight)
	: mapCell(sf::Vector2f(CELL_SIZE, CELL_SIZE))
{
	// Making sure that width and height of the map are odd numbers not less than MIN_MAP_SIZE
	this->mapWidth = (_mapWidth < MIN_MAP_SIZE) ? MIN_MAP_SIZE : _mapWidth;
	this->mapHeight = (_mapHeight < MIN_MAP_SIZE) ? MIN_MAP_SIZE : _mapHeight;
	this->mapWidth += (this->mapWidth % 2) ? 0 : 1;
	this->mapHeight += (this->mapHeight % 2) ? 0 : 1;

	// Setting starting cell to top left corner and ending cell to bottom right corner
	this->startingCellPosition = sf::Vector2f(CELL_SIZE, CELL_SIZE);
	this->endingCellPosition = sf::Vector2f(CELL_SIZE * float(this->mapWidth - 2), CELL_SIZE * float(this->mapHeight - 2));

	MazeGenerator mazeGenerator(this->mapWidth, this->mapHeight);
	this->map = mazeGenerator.createMap();
}

bool Maze::mapAt(unsigned int x, unsigned int y)
{
	return this->map[y * this->mapWidth + x];
}

unsigned int Maze::getMapWidth()
{
	return this->mapWidth;
}

unsigned int Maze::getMapHeight()
{
	return this->mapHeight;
}

std::shared_ptr<bool[]> Maze::getMap()
{
	return this->map;
}

bool Maze::isLevelFinished(Player& _player)
{
	this->mapCell.setPosition(this->endingCellPosition);
	if (this->mapCell.getGlobalBounds().contains(_player.getPosition() - _player.getOrigin()))
		return true;

	return false;
}

void Maze::handleCollisions(Player& _player)
{
	int playerCellX = int(_player.getPosition().x / CELL_SIZE);
	int playerCellY = int(_player.getPosition().y / CELL_SIZE);

	sf::FloatRect intersection;

	// top collision
	if (this->mapAt(playerCellX, playerCellY - 1))
	{
		this->mapCell.setPosition(CELL_SIZE * playerCellX, CELL_SIZE * (playerCellY - 1));

		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds()))

			_player.setPosition(_player.getPosition().x, playerCellY * CELL_SIZE + HALF_OF_PLAYER_SIZE);
	}

	// left collision
	if (this->mapAt(playerCellX - 1, playerCellY))
	{
		this->mapCell.setPosition(CELL_SIZE * (playerCellX - 1), CELL_SIZE * playerCellY);

		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds()))

			_player.setPosition(playerCellX * CELL_SIZE + HALF_OF_PLAYER_SIZE, _player.getPosition().y);
	}

	// right collision
	if (this->mapAt(playerCellX + 1, playerCellY))
	{
		this->mapCell.setPosition(CELL_SIZE * (playerCellX + 1), CELL_SIZE * playerCellY);

		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds()))

			_player.setPosition((playerCellX + 1) * CELL_SIZE - HALF_OF_PLAYER_SIZE, _player.getPosition().y);
	}

	// bottom collision	
	if (this->mapAt(playerCellX, playerCellY + 1))
	{
		this->mapCell.setPosition(CELL_SIZE * playerCellX, CELL_SIZE * (playerCellY + 1));

		if (_player.getGlobalBounds().intersects(mapCell.getGlobalBounds()))

			_player.setPosition(_player.getPosition().x, (playerCellY + 1) * CELL_SIZE - HALF_OF_PLAYER_SIZE);
	}

	// left top collision
	if (this->mapAt(playerCellX - 1, playerCellY - 1))
	{
		this->mapCell.setPosition(CELL_SIZE * (playerCellX - 1), CELL_SIZE * (playerCellY - 1));

		if (_player.getGlobalBounds().intersects(this->mapCell.getGlobalBounds(), intersection))

			if (intersection.width < intersection.height)
				_player.setPosition(playerCellX * CELL_SIZE + HALF_OF_PLAYER_SIZE, _player.getPosition().y);
			else
				_player.setPosition(_player.getPosition().x, playerCellY * CELL_SIZE + HALF_OF_PLAYER_SIZE);
	}

	// right top collision
	if (this->mapAt(playerCellX + 1, playerCellY - 1))
	{
		this->mapCell.setPosition(CELL_SIZE * (playerCellX + 1), CELL_SIZE * (playerCellY - 1));

		if (_player.getGlobalBounds().intersects(this->mapCell.getGlobalBounds(), intersection))

			if (intersection.width < intersection.height)
				_player.setPosition((playerCellX + 1) * CELL_SIZE - HALF_OF_PLAYER_SIZE, _player.getPosition().y);
			else
				_player.setPosition(_player.getPosition().x, playerCellY * CELL_SIZE + HALF_OF_PLAYER_SIZE);
	}

	// left bottom collision
	if (this->mapAt(playerCellX - 1, playerCellY + 1))
	{
		this->mapCell.setPosition(CELL_SIZE * (playerCellX - 1), CELL_SIZE * (playerCellY + 1));

		if (_player.getGlobalBounds().intersects(this->mapCell.getGlobalBounds(), intersection))

			if (intersection.width < intersection.height)
				_player.setPosition(playerCellX * CELL_SIZE + HALF_OF_PLAYER_SIZE, _player.getPosition().y);
			else
				_player.setPosition(_player.getPosition().x, (playerCellY + 1) * CELL_SIZE - HALF_OF_PLAYER_SIZE);
	}

	// right bottom collision
	if (this->mapAt(playerCellX + 1, playerCellY + 1))
	{
		this->mapCell.setPosition(CELL_SIZE * (playerCellX + 1), CELL_SIZE * (playerCellY + 1));

		if (_player.getGlobalBounds().intersects(this->mapCell.getGlobalBounds(), intersection))

			if (intersection.width < intersection.height)
				_player.setPosition((playerCellX + 1) * CELL_SIZE - HALF_OF_PLAYER_SIZE, _player.getPosition().y);
			else
				_player.setPosition(_player.getPosition().x, (playerCellY + 1) * CELL_SIZE - HALF_OF_PLAYER_SIZE);
	}
}

void Maze::draw(sf::RenderWindow& _window)
{
	this->mapCell.setFillColor(sf::Color::White);

	for (unsigned int y = 0; y < this->mapHeight; y++)
	{
		for (unsigned int x = 0; x < this->mapWidth; x++)
		{
			if (!this->mapAt(x, y)) // if the map at (x,y) is true then there is a wall, if false then there is a path
			{
				this->mapCell.setPosition(CELL_SIZE * x, CELL_SIZE * y);
				_window.draw(this->mapCell);
			}
		}
	}

	this->mapCell.setFillColor(MAIN_COLOR);

	this->mapCell.setPosition(this->startingCellPosition);
	_window.draw(this->mapCell);

	this->mapCell.setPosition(this->endingCellPosition);
	_window.draw(this->mapCell);
}
