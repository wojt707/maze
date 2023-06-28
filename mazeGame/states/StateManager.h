#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H
#pragma once

#include <stack>
#include <memory>
#include <iostream>

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
	void popAllAndChange(std::unique_ptr<State> _state);
	void changeState(std::unique_ptr<State> _state);


	void handleInput();
	void update(sf::Time& _deltaTime);
	void draw();

	void quit();
};

#endif // !STATE_MANAGER_H
