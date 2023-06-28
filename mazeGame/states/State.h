#ifndef STATE_H
#define STATE_H
#pragma once

#include <SFML/System.hpp>

class GameData;

class State
{
protected:
	GameData& data;
public:
	State(GameData& _data)
		: data(_data) { }
	virtual ~State() { }

	//virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update(sf::Time& _deltaTime) = 0;
	virtual void draw() = 0;
	//virtual void pause() = 0;
	//virtual void resume() = 0;
};

#endif // !STATE_H
