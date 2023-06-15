#include "Game.h"

Game::Game()
	: window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze", sf::Style::Close | sf::Style::Titlebar)
{
	// TO DO
	// concurrently load resources, maybe not here
	this->resourceManager.fonts.load(FontIDs::MAIN_FONT, "media/fonts/PTC55F.ttf");
	this->resourceManager.sounds.load(SoundIDs::SAMPLE_SOUND, "media/sounds/sample.wav");
	this->resourceManager.textures.load(TextureIDs::TREE, "media/textures/tree.png");

	this->window.setFramerateLimit(120);
}

void Game::run()
{
	std::unique_ptr<State> menuState = std::make_unique<MenuState>(this->stateManager, this->resourceManager, this->window);
	this->stateManager.changeState(std::move(menuState));

	sf::Clock clock;

	while (this->stateManager.isRunning)
	{
		sf::Time deltaTime = clock.restart();
		this->stateManager.handleInput();
		this->stateManager.update(deltaTime);
		this->stateManager.draw();
	}

}
