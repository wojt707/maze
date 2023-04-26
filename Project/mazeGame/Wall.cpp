#include "Wall.h"

Wall::Wall(Cell& _firstCell, Cell& _secondCell, bool _isHorizontal)
	: firstCell(_firstCell), secondCell(_secondCell), isHorizontal(_isHorizontal) { }

bool Wall::isBetweenConnectedCells()
{
	return this->firstCell.isConnectedWith(this->secondCell);
}

void Wall::joinCells()
{
	this->firstCell.joinCell(this->secondCell);
}

void Wall::remove()
{
	if (this->isHorizontal)
		this->firstCell.destroyRightWall();
	else
		this->firstCell.destroyBottomWall();
}
