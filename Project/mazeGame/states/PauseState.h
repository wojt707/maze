#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "../GameData.h"
#include "../Constants.h"
#include "MenuState.h"
#include "HowToPlayState.h"
#include "../button/ButtonList.h"
#include "../SaveableData.h"

class PauseState : public State
{
private:
	ButtonList pauseStateButtons;
	sf::Text pauseStateText;

	std::shared_ptr<SaveableData> dataToSave;

	void handleEnter();
public:
	PauseState(GameData& _data, std::shared_ptr<SaveableData> _dataToSave);
	~PauseState();

	void handleInput() override;
	void update(sf::Time& _deltaTime) override;
	void draw() override;
};

#endif // !PAUSE_STATE_H
