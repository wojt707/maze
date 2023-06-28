#include "Game.h"

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (const std::exception& e)
	{
		std::cout << std::endl << "EXCEPTION " << e.what() << std::endl;
	}

	return 0;
}

