#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#pragma once

#include "StateManager.h"

class PauseState : public State
{
public:
	PauseState(StateManager& _stateManager, sf::RenderWindow& _window);
	~PauseState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif
