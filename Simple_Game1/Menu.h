#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenuData.h"
#include <vector>
#include "MenuItem.h"
#include "GameState.h"

//Main menu class
class Menu
{
	sf::RenderWindow* window;	//only for access, not for memory allocation
	DATA::MainMenuData data;	//textures

	sf::Sprite background;
	sf::Sprite selecting_mark;

	float buttons_indent_x;
	std::vector<MenuItem> buttons;

	void init();

	void addMenuItem(sf::Texture& t, GAMESTATE action);

	void adjust_buttons();

	void checkForSelect();


	void draw_frame();

public:
	Menu() = delete;
	Menu(const Menu&) = delete;

	Menu(sf::RenderWindow* win);

	

	GAMESTATE run();

};

