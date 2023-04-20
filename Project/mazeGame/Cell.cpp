#include "Cell.h"

Cell::Cell()
{
	this->rightWall = true;
	this->bottomWall = true;
	this->group = nullptr;
}

void Cell::init()
{
	this->group = std::make_shared<std::vector<Cell*>>(1, this);
}

void Cell::joinCell(Cell& another)
{
	//perform only if cells are not connected
	auto oldGroup = another.group;
	for (auto c = oldGroup->begin(); c != oldGroup->end(); c++)
		(*c)->group = this->group;

	this->group->insert(group->end(), oldGroup->begin(), oldGroup->end());
}

bool Cell::isConnectedWith(Cell& another)
{
	return this->group == another.group;
}


void Cell::destroyRightWall()
{
	this->rightWall = false;
}

void Cell::destroyBottomWall()
{
	this->bottomWall = false;
}
