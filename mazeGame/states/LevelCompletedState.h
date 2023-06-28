#ifndef LEVEL_COMPLETED_STATE_H
#define LEVEL_COMPLETED_STATE_H
#pragma once

#include <future>
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "../GameData.h"
#include "../Constants.h"
#include "GameState.h"
#include "MenuState.h"
#include "../button/ButtonList.h"
#include "../Maze.h"

class LevelCompletedState : public State
{
private:
	ButtonList levelCompletedButtons;
	sf::Text levelCompletedText;

	std::shared_ptr<SaveableData> dataToSave;
	std::unique_ptr<std::future<std::unique_ptr<Maze>>> nextLevelMaze;
	int completedLevel;

	void handleEnter();
public:
	LevelCompletedState(GameData& _data,
		std::shared_ptr<SaveableData> _dataToSave,
		std::unique_ptr<std::future<std::unique_ptr<Maze>>> _nextLevelMaze,
		int _completedLevel);
	~LevelCompletedState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !LEVEL_COMPLETED_STATE_H
