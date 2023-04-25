#ifndef CELL_H
#define CELL_H
#pragma once

#include <vector>
#include <memory>

class Cell
{
private:
	std::shared_ptr<std::vector<Cell*>> group;

public:
	bool rightWall;
	bool bottomWall;

	Cell();
	void init();

	void joinCell(Cell& another);
	bool isConnectedWith(Cell& another);

	void destroyRightWall();
	void destroyBottomWall();
};

#endif
