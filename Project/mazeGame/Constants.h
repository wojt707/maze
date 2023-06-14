#ifndef CONSTANTS_H
#define CONSTANTS_H
#pragma once

constexpr float TWO_PI = 6.28318530718f; // 360 degrees;
constexpr float PI = 3.14159265359f; // 180 degrees;
constexpr float HALF_OF_PI = 1.5707963268f; // 90 degrees;

constexpr float PLAYER_SIZE = 30.0f;
constexpr float HALF_OF_PLAYER_SIZE = PLAYER_SIZE / 2;
constexpr float PLAYER_ROTATION_RATE = 0.02f;
constexpr float PLAYER_DISPLACEMENT_RATE = 0.01f;

constexpr float BUTTON_WIDTH = 500.0f;
constexpr float BUTTON_HEIGHT = 80.0f;

constexpr unsigned int CELL_SIZE = 80;

constexpr unsigned int MIN_MAP_SIZE = 9;

constexpr unsigned int SCREEN_WIDTH = 1600;
constexpr unsigned int SCREEN_HEIGHT = 800;

const sf::Color MAIN_COLOR(13, 100, 150);

#endif
