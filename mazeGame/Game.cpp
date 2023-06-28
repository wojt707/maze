#include "Game.h"

Game::Game()
{
	this->data.window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze", sf::Style::Close | sf::Style::Titlebar);
	this->data.window.setFramerateLimit(120);

	// TO DO
	// concurrently load resources, maybe not here
	this->data.resourceManager.fonts.load(FontIDs::MAIN_FONT, "media/fonts/PTC55F.ttf");
	this->data.resourceManager.sounds.load(SoundIDs::SAMPLE_SOUND, "media/sounds/sample.wav");
	this->data.resourceManager.textures.load(TextureIDs::TREE, "media/textures/tree.png");
}

void Game::run()
{
	std::unique_ptr<State> menuState = std::make_unique<MenuState>(this->data);
	this->data.stateManager.changeState(std::move(menuState));

	sf::Clock clock;
	
	int renderCounter = 0;
	const int renderNumber = 200;
	sf::Time totalTime = sf::Time::Zero;

	while (this->data.stateManager.isRunning)
	{
		sf::Time deltaTime = clock.restart();
		this->data.stateManager.handleInput();
		this->data.stateManager.update(deltaTime);
		this->data.stateManager.draw();

		totalTime += deltaTime;
		renderCounter++;
		if (renderCounter == renderNumber)
		{
			std::cout << "Mean of " << renderNumber << " renders: " << float(totalTime.asMicroseconds()) / renderNumber << " us" << std::endl;
			std::cout << "Mean FPS: " << 1.0f/ totalTime.asSeconds() * renderNumber << " ms" << std::endl << std::endl;
			
			totalTime = sf::Time::Zero;
			renderCounter = 0;
		}
	}

}
