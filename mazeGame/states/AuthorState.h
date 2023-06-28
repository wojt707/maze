#ifndef AUTHOR_STATE_H
#define AUTHOR_STATE_H
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "State.h"
#include "../GameData.h"
#include "../Constants.h"

class AuthorState : public State
{
private:
	sf::Text aboutAuthor;
public:
	AuthorState(GameData& _data);
	~AuthorState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !AUTHOR_STATE_H
