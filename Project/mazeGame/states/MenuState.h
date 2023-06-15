#ifndef MENU_STATE_H
#define MENU_STATE_H
#pragma once

#include "StateManager.h"
#include "GameState.h"
#include "../resources/ResourceIdentifiers.h"
#include "../button/ButtonList.h"

class MenuState : public State
{
private:
	ButtonList menuButtons;
	sf::Text menuText;
	void handleEnter();
public:
	MenuState(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window);
	~MenuState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !MENU_STATE_H
