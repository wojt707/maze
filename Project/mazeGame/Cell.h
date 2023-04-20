#pragma once
#include <vector>
#include <memory>
#include <iostream>

class Cell
{
private:

public:
	std::shared_ptr<std::vector<Cell*>> group;
	bool rightWall;
	bool bottomWall;	


	Cell();
	void init();

	void joinCell(Cell& another);
	bool isConnectedWith(Cell& another);

	void destroyRightWall();
	void destroyBottomWall();
};
