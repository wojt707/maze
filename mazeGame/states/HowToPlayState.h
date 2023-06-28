#ifndef HOW_TO_PLAY_STATE_H
#define HOW_TO_PLAY_STATE_H
#pragma once

#include <iostream>
//#include <memory>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "../GameData.h"
#include "../Constants.h"
//#include "GameState.h"
//#include "../button/ButtonList.h"

class HowToPlayState : public State
{
private:
	sf::Text description;
public:
	HowToPlayState(GameData& _data);
	~HowToPlayState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !HOW_TO_PLAY_STATE_H
