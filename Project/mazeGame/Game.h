#ifndef GAME_H
#define GAME_H
#pragma once

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameData.h"
#include "Constants.h"
#include "states/State.h"
#include "states/MenuState.h"

class Game
{
private:
	GameData data;
public:
	Game();
	void run();
};

#endif // !GAME_H
