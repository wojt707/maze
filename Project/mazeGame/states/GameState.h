#ifndef GAME_STATE_H
#define GAME_STATE_H
#pragma once

#include <future>
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
 
#include "State.h"
#include "../GameData.h"
#include "../Constants.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "LevelCompletedState.h"
#include "../Maze.h"
#include "../Player.h"
#include "../ViewHandler.h"
#include "../SaveableData.h"

class GameState : public State
{
private:
	ViewHandler viewHandler;
	std::unique_ptr<Maze> maze;
	Player player;
	int level;
	sf::Text textLevel;

	std::shared_ptr<SaveableData> saveableData;
	std::unique_ptr<std::future<std::unique_ptr<Maze>>> nextLevelMaze;

	std::unique_ptr<std::future<std::unique_ptr<Maze>>> generateNextLevelMaze();
	void finishLevel();
	void failLevel();
	void pauseLevel();
	void prepareToExit(bool _isLevelCompleted);

public:
	GameState(GameData& _data, int _level);
	GameState(GameData& _data, std::unique_ptr<Maze> _previouslyGeneratedMaze, int _level);
	~GameState();
	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !GAME_STATE_H
