#include <iostream>
#include "StateManager.h"

StateManager::StateManager()
	: isRunning(true)
{
	std::cout << "State Manager initialized" << std::endl;
}

StateManager::~StateManager()
{
	while (!this->states.empty())
		this->popState();

	std::cout << "State Manager destroyed" << std::endl;
}

void StateManager::pushState(std::unique_ptr<State> _state)
{
	this->states.push(std::move(_state));
}

void StateManager::popState()
{
	this->states.pop();
}

void StateManager::changeState(std::unique_ptr<State> _state)
{
	if (!this->states.empty())
	{
		this->popState();
	}
	this->pushState(std::move(_state));

}

void StateManager::handleInput()
{
	this->states.top()->handleInput();
}

void StateManager::update(sf::Time& _deltaTime)
{
	this->states.top()->update(_deltaTime);
}

void StateManager::draw()
{
	this->states.top()->draw();
}
