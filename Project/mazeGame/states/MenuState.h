#ifndef MENU_STATE_H
#define MENU_STATE_H
#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
 
#include "State.h"
#include "../GameData.h"
#include "../Constants.h"
#include "GameState.h"
#include "../button/ButtonList.h"

class MenuState : public State
{
private:
	ButtonList menuButtons;
	sf::Text menuText;
	void handleEnter();
public:
	MenuState(GameData& _data);
	~MenuState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !MENU_STATE_H
