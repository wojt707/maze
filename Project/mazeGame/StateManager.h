#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H
#pragma once

#include <stack>
#include <memory>

#include "State.h"

class StateManager
{
private:
	std::stack<std::unique_ptr<State>> states;
public:
	bool isRunning;

	StateManager();
	~StateManager();

	void pushState(std::unique_ptr<State> _state);
	void popState();
	void changeState(std::unique_ptr<State> _state);


	void handleInput();
	void update(sf::Time& _deltaTime);
	void draw();

	void quit() { this->isRunning = false; }
};

#endif