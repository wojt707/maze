#ifndef WALL_H
#define WALL_H
#pragma once

#include <memory>

#include "Cell.h"

class Wall
{
private:
	bool isHorizontal;
	Cell* firstCell;
	Cell* secondCell;

public:

	Wall(Cell& _firstCell, Cell& _secondCell, bool _isHorizontal);

	bool isBetweenConnectedCells();
	void joinCells();
	void remove();
};

#endif
