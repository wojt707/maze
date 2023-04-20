#pragma once
#include <memory>

#include "Cell.h"

class Wall
{
public:
	Cell* firstCell;
	Cell* secondCell;
	bool isHorizontal;

	Wall(Cell& _firstCell, Cell& _secondCell, bool _isHorizontal);
	
	void remove();
};

