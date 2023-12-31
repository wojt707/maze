#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(unsigned  int _mapWidth, unsigned int _mapHeight)
	: rows((_mapHeight - 1) / 2),
	cols((_mapWidth - 1) / 2),
	mapWidth(_mapWidth),
	mapHeight(_mapHeight)
{
	for (unsigned int r = 0; r < this->rows; r++)
	{
		std::vector<Cell> row;
		for (unsigned int c = 0; c < this->cols; c++)
			row.push_back(Cell());

		this->cells.push_back(row);
	}
	for (auto& row : this->cells)
		for (auto& cell : row)
			cell.init();
	this->generate();
}

void MazeGenerator::generate()
{
	this->createWalls();
	this->shuffleWalls();

	for (auto& wall : this->walls)
		if (!wall.isBetweenConnectedCells())
		{
			wall.joinCells();
			wall.remove();
		}
}

void MazeGenerator::createWalls()
{
	for (unsigned int r = 0; r < this->rows - 1; r++)
	{
		for (unsigned int c = 0; c < this->cols - 1; c++)
		{
			Wall toRight(this->cells[r][c], this->cells[r][c + 1], true);
			Wall toBottom(this->cells[r][c], this->cells[r + 1][c], false);
			this->walls.push_back(toRight);
			this->walls.push_back(toBottom);
		}
		Wall toBottom(this->cells[r][this->cols - 1], this->cells[r + 1][this->cols - 1], false);
		this->walls.push_back(toBottom);
	}
	for (unsigned int c = 0; c < this->cols - 1; c++)
	{
		Wall toRight(this->cells[this->rows - 1][c], this->cells[this->rows - 1][c + 1], true);
		this->walls.push_back(toRight);
	}
}

void MazeGenerator::shuffleWalls()
{
	// Shuffle a range of pointers to walls
	std::vector<Wall*> wallPointers;
	wallPointers.reserve(this->walls.size());
	for (Wall& wall : this->walls)
		wallPointers.push_back(&wall);

	std::shuffle(wallPointers.begin(), wallPointers.end(), std::default_random_engine{ std::random_device {}() });

	// Reorder the walls vector based on the shuffled pointers
	std::vector<Wall> shuffledWalls;
	shuffledWalls.reserve(this->walls.size());

	for (Wall* wallPtr : wallPointers)
		shuffledWalls.push_back(*wallPtr);

	this->walls = std::move(shuffledWalls);
}

std::shared_ptr<bool[]> MazeGenerator::createMap()
{
	std::shared_ptr<bool[]> map = std::make_shared<bool[]>(this->mapHeight * this->mapWidth);
	std::fill(map.get(), map.get() + this->mapHeight * this->mapWidth, true);

	for (unsigned int r = 0; r < this->rows; r++)
	{
		for (unsigned int c = 0; c < this->cols; c++)
		{
			map[(2 * r + 1) * this->mapWidth + (2 * c + 1)] = false;

			if (!this->cells[r][c].hasRightWall())
				map[(2 * r + 1) * this->mapWidth + (2 * c + 2)] = false;

			if (!this->cells[r][c].hasBottomWall())
				map[(2 * r + 2) * this->mapWidth + (2 * c + 1)] = false;
		}
	}
	return map;
}
