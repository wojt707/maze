#include "Wall.h"

Wall::Wall(Cell& _firstCell, Cell& _secondCell, bool _isHorizontal)
{
	this->firstCell =  &_firstCell;
	this->secondCell = &_secondCell;
	this->isHorizontal = _isHorizontal;
}

void Wall::remove()
{
	if (this->isHorizontal)
		this->firstCell->destroyRightWall();
	else
		this->firstCell->destroyBottomWall();
}

