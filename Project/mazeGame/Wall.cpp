#include "Wall.h"

Wall::Wall(Cell& _firstCell, Cell& _secondCell, bool _isHorizontal)
{
	this->firstCell =  &_firstCell;
	this->secondCell = &_secondCell;
	this->isHorizontal = _isHorizontal;
}

bool Wall::isBetweenConnectedCells()
{
	return this->firstCell->isConnectedWith(*this->secondCell);
}

void Wall::joinCells()
{
	this->firstCell->joinCell(*this->secondCell);
}

void Wall::remove()
{
	if (this->isHorizontal)
		this->firstCell->destroyRightWall();
	else
		this->firstCell->destroyBottomWall();
}

