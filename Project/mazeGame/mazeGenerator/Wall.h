#ifndef WALL_H
#define WALL_H
#pragma once

#include <memory>

#include "Cell.h"

class Wall
{
private:
	Cell& firstCell;
	Cell& secondCell;
	bool isHorizontal;

public:

	Wall(Cell& _firstCell, Cell& _secondCell, bool _isHorizontal);
	// TODO (maybe)
	// Delete the copy constructor
	//Wall(const Wall&) = delete;
	// Delete the copy assignment operator
	//Wall& operator=(const Wall&) = delete;

	bool isBetweenConnectedCells();
	void joinCells();
	void remove();
};

#endif // !WALL_H
