#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#pragma once

#include "StateManager.h"
#include "MenuState.h"
#include "../button/ButtonList.h"

class PauseState : public State
{
private:
	ButtonList pauseStateButtons;
	void handleEnter();
public:
	PauseState(StateManager& _stateManager, sf::RenderWindow& _window);
	~PauseState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif
