#pragma once
#include <SFML/Graphics.hpp>

#include "GameData.h"

#include "GameState.h"

#include "Menu.h"

//#include "Player.h"

class Game : public GameData
{
	sf::RenderWindow* window;	//only for access, not for memory allocation
	GAMESTATE state;

	void initData();

public:
	Game(const Game&) = delete;
	Game() = delete;

	explicit Game(sf::RenderWindow* win);

	GAMESTATE getState() const;

	void menu();

	void play();

};

