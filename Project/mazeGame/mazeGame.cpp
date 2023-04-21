#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include "Maze.h"
#include "Player.h"

int main()
{	
	const unsigned int screen = 800;
	const unsigned int cols = 10;
	const unsigned int rows = 5;

	unsigned int screenWidth = (cols * 2 + 1) * cellSideLength;
	unsigned int screenHeight = (rows * 2 + 1) * cellSideLength;


	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Maze");

	Maze maze(rows, cols);

	Player player(sf::Vector2f(20.0f, 20.0f), 1.0f);

	sf::Clock clock;

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
		sf::Time deltaTime = clock.restart();

		player.handleInput();
		player.update(deltaTime);

		window.clear(sf::Color::Black);

		maze.draw(window);
		player.draw(window);

		window.display();
	}

	return 0;
}
