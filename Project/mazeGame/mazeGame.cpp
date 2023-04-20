#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Maze.h"

int main()
{
	const unsigned int cols = 5;
	const unsigned int rows = 10;
	Maze maze;
	maze.generate();
	maze.draw();

	return 0;
	sf::RenderWindow window(sf::VideoMode(600, 800), "Some title");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				if (event.text.unicode < 128)
				{
					char c = event.text.unicode;
					std::cout << c;
				}
			default:
				break;
			}

		}

	}



	return 0;
}
