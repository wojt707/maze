#ifndef LEVEL_COMPLETED_STATE_H
#define LEVEL_COMPLETED_STATE_H
#pragma once

#include "StateManager.h"
#include "GameState.h"
#include "MenuState.h"
#include "../button/ButtonList.h"

class LevelCompletedState : public State
{
private:
	ButtonList levelCompletedButtons;
	void handleEnter();
public:
	LevelCompletedState(StateManager& _stateManager, sf::RenderWindow& _window);
	~LevelCompletedState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif

