#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H
#pragma once

#include "StateManager.h"
#include "GameState.h"
#include "MenuState.h"
#include "../button/ButtonList.h"

class GameOverState : public State
{
private:
	ButtonList gameOverButtons;
	sf::Text gameOverText;
	void handleEnter();
public:
	GameOverState(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window);
	~GameOverState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !GAME_OVER_STATE_H
