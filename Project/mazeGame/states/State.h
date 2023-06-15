#ifndef STATE_H
#define STATE_H
#pragma once

#include <SFML/Graphics.hpp>
#include "../resources/ResourceManager.h"

class StateManager;

class State
{
protected:
	StateManager& stateManager;
	ResourceManager& resourceManager;
	sf::RenderWindow& window;
public:
	State(StateManager& _stateManager, ResourceManager& _resourceManager, sf::RenderWindow& _window)
		: stateManager(_stateManager),
		resourceManager(_resourceManager),
		window(_window) { }
	virtual ~State() { }

	//virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update(sf::Time& _deltaTime) = 0;
	virtual void draw() = 0;
	//virtual void pause() = 0;
	//virtual void resume() = 0;
};

#endif // !STATE_H
