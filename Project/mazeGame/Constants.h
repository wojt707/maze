#ifndef CONSTANTS_H
#define CONSTANTS_H
#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

constexpr float TWO_PI = 6.28318530718f; // 360 degrees;
constexpr float PI = 3.14159265359f; // 180 degrees;
constexpr float HALF_OF_PI = 1.5707963268f; // 90 degrees;

constexpr float PLAYER_SIZE = 30.0f;
constexpr float HALF_OF_PLAYER_SIZE = PLAYER_SIZE / 2;
constexpr float PLAYER_ROTATION_RATE = 0.02f;
constexpr float PLAYER_DISPLACEMENT_RATE = 0.01f;

constexpr float BUTTON_WIDTH = 500.0f;
constexpr float BUTTON_HEIGHT = 80.0f;

constexpr float CELL_SIZE = 80.0f;

constexpr unsigned int MIN_MAP_SIZE = 7;

constexpr unsigned int SCREEN_WIDTH = 1600;
constexpr unsigned int SCREEN_HEIGHT = 800;

constexpr float MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES = 95.0f;
//constexpr unsigned int MAX_VIEW_DISTANCE_FROM_WINDOW_EDGES = 300;

const std::vector<std::string> MENU_OPTIONS = { "Play", "Load game save", "How to play", "Author", "Quit" };
const std::vector<std::string> PAUSE_OPTIONS = { "Resume", "Save and go to menu", "How to play", "Quit" };
const std::vector<std::string> GAME_OVER_OPTIONS = { "Restart", "Save and go to menu", "Quit" };
const std::vector<std::string> LEVEL_COMPLETED_OPTIONS = { "Next level", "Save and go to menu", "Quit" };

const sf::Color MAIN_COLOR(13, 100, 150);

#endif // !CONSTANTS_H
