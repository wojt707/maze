#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Maze.h"


int main()
{
	const unsigned int screen = 800;
	Maze maze(10,10);

	sf::RenderWindow window(sf::VideoMode(screen, screen), "Maze");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			default:
				break;
			}
		}

		window.clear(sf::Color::Black);
		maze.draw(window);
		
		window.display();
	}

	return 0;
}
