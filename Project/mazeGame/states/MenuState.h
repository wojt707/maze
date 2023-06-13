#ifndef MENU_STATE_H
#define MENU_STATE_H
#pragma once

#include "StateManager.h"
#include "GameState.h"
#include "../button/ButtonList.h"

class MenuState : public State
{
private:
	ButtonList menuButtons;
	void handleEnter();
public:
	MenuState(StateManager& _stateManager, sf::RenderWindow& _window);
	~MenuState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif
