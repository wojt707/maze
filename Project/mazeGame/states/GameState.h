#ifndef GAME_STATE_H
#define GAME_STATE_H
#pragma once

#include "StateManager.h"
#include "PauseState.h"
#include "../Maze.h"
#include "../Player.h"
#include "../Constants.h"

class GameState : public State
{
private:
	Player player;
	Maze maze;
public:
	GameState(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window);
	~GameState();
	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !GAME_STATE_H
