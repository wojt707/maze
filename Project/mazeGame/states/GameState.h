#ifndef GAME_STATE_H
#define GAME_STATE_H
#pragma once

#include <future>

#include "StateManager.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "LevelCompletedState.h"
#include "../Maze.h"
#include "../Player.h"
#include "../Constants.h"

class GameState : public State
{
private:
	std::unique_ptr<Maze> maze;
	Player player;
	int level;
	sf::Text textLevel;

	std::unique_ptr<std::future<std::unique_ptr<Maze>>> nextLevelMaze;

	std::unique_ptr<std::future<std::unique_ptr<Maze>>> generateNextLevelMaze();
	void finishLevel();
	void failLevel();

public:
	GameState(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window, int _level);
	GameState(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window, std::unique_ptr<Maze> _previouslyGeneratedMaze, int _level);
	~GameState();
	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !GAME_STATE_H
