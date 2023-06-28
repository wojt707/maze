#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H
#pragma once

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "../GameData.h"
#include "../Constants.h"
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
	GameOverState(GameData& _data);
	~GameOverState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !GAME_OVER_STATE_H
