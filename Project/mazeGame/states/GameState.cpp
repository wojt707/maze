#include "GameState.h"

GameState::GameState(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window, int _level)
	: State(_stateManager, _resourceManager, _window),
	// For now squared map are created
	// e.g. level 1 -> map 7x7, level 2 -> map 9x9, level 3 -> map 11x11
	// TODO maybe creating not only square maps
	//viewHandler((MIN_MAP_SIZE + (_level - 1) * 2)* CELL_SIZE, (MIN_MAP_SIZE + (_level - 1) * 2)* CELL_SIZE),
	maze(std::make_unique<Maze>(MIN_MAP_SIZE + (_level - 1) * 2, MIN_MAP_SIZE + (_level - 1) * 2)),
	player(sf::Vector2f(CELL_SIZE * 1.5f, CELL_SIZE * 1.5f), 200.0f),
	level(_level),
	textLevel("Level " + std::to_string(_level), *(this->resourceManager.fonts.get(FontIDs::MAIN_FONT)))
{
	textLevel.setPosition(sf::Vector2f(500.0f, 0.0f));

	this->nextLevelMaze = this->generateNextLevelMaze();

	std::cout << "GameState level " << _level << " initialized with now generated maze" << std::endl;
}

GameState::GameState(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window, std::unique_ptr<Maze> _previouslyGeneratedMaze, int _level)
	: State(_stateManager, _resourceManager, _window),
	//viewHandler((MIN_MAP_SIZE + (_level - 1) * 2)* CELL_SIZE, (MIN_MAP_SIZE + (_level - 1) * 2)* CELL_SIZE),
	maze(std::move(_previouslyGeneratedMaze)),
	player(sf::Vector2f(CELL_SIZE * 1.5f, CELL_SIZE * 1.5f), 200.0f),
	level(_level),
	textLevel("Level " + std::to_string(_level), *(this->resourceManager.fonts.get(FontIDs::MAIN_FONT)))
{
	textLevel.setPosition(sf::Vector2f(500.0f, 0.0f));

	this->nextLevelMaze = this->generateNextLevelMaze();

	std::cout << "GameState level " << _level << " initialized with previously generated maze" << std::endl;
}

GameState::~GameState()
{
	std::cout << "GameState destroyed" << std::endl;
}

std::unique_ptr<std::future<std::unique_ptr<Maze>>> GameState::generateNextLevelMaze()
{
	return std::make_unique<std::future<std::unique_ptr<Maze>>>(std::async(std::launch::async, [this]() -> std::unique_ptr<Maze> {
		std::cout << "async maze level " << level + 1 << " started" << std::endl;
	return std::make_unique<Maze>(MIN_MAP_SIZE + level * 2, MIN_MAP_SIZE + level * 2);
		}));
}

void GameState::finishLevel()
{
	this->viewHandler.resetViewAt(this->window);
	std::unique_ptr<State> levelCompletedState = std::make_unique<LevelCompletedState>(this->stateManager, this->resourceManager, this->window, std::move(this->nextLevelMaze), this->level);
	this->stateManager.pushState(std::move(levelCompletedState));
}

void GameState::failLevel()
{
	this->viewHandler.resetViewAt(this->window);
	std::unique_ptr<State> levelFailedState = std::make_unique<GameOverState>(this->stateManager, this->resourceManager, this->window);
	this->stateManager.changeState(std::move(levelFailedState));
}

void GameState::handleInput()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			this->stateManager.quit();
			break;
		case sf::Event::LostFocus:
		{
			this->viewHandler.resetViewAt(this->window);
			std::unique_ptr<State> pauseState = std::make_unique<PauseState>(this->stateManager, this->resourceManager, this->window);
			this->stateManager.pushState(std::move(pauseState));
			return;
		}
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Escape:
				this->viewHandler.resetViewAt(this->window);
				std::unique_ptr<State> pauseState = std::make_unique<PauseState>(this->stateManager, this->resourceManager, this->window);
				this->stateManager.pushState(std::move(pauseState));
				return;
			}
			break;
		default:
			break;
		}
	}
	this->player.handleInput();
}

void GameState::update(sf::Time& _deltaTime)
{
	this->player.update(_deltaTime);

	this->maze->handleCollisions(this->player);

	this->viewHandler.updateRelativeTo(this->player, _deltaTime);

	this->viewHandler.setViewAt(this->window);

	if (this->maze->isLevelFinished(this->player))
		this->finishLevel();
}

void GameState::draw()
{
	this->window.clear(sf::Color::Black);

	this->maze->draw(this->window);
	this->player.draw(this->window);

	this->window.draw(this->textLevel);

	this->window.display();
}
