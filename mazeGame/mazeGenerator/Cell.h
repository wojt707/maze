#ifndef CELL_H
#define CELL_H
#pragma once

#include <vector>
#include <memory>

class Cell
{
private:
	std::shared_ptr<std::vector<Cell*>> group;
	bool rightWall;
	bool bottomWall;

public:
	Cell();
	// TODO (maybe)
	// Delete the copy constructor
	//Cell(const Cell&) = delete;

	// Delete the copy assignment operator
	//Cell& operator=(const Cell&) = delete;
	void init();

	void joinCell(Cell& another);
	bool isConnectedWith(Cell& another);

	bool hasRightWall();
	bool hasBottomWall();

	void destroyRightWall();
	void destroyBottomWall();
};

#endif // !CELL_H
