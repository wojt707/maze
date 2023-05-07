#ifndef STATE_H
#define STATE_H
#pragma once

#include <SFML/Graphics.hpp>

class StateManager;

class State
{
protected:
	StateManager& stateManager;
	sf::RenderWindow& window;
public:
	State(StateManager& _stateManager, sf::RenderWindow& _window)
		: stateManager(_stateManager), window(_window) { }
	virtual ~State() { }

	//virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update(sf::Time& _deltaTime) = 0;
	virtual void draw() = 0;
	//virtual void pause() = 0;
	//virtual void resume() = 0;
};

#endif
