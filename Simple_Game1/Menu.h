#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MenuStateBase.h"
#include "MainMenuState.h"


class Menu
{
public:
	Menu(Game& game, MenuStateBase* state = new MainMenuState);

	Menu(const Menu&) = delete;


	void run();

	const sf::Sprite& selectButton() const;
	const sf::Sprite& settingsButton() const;
	const sf::Sprite& exitButton() const;

	Game& game_;
private:

	~Menu();


	sf::Sprite select_level_s;
	sf::Texture select_level_t;


	sf::Sprite settings_s;
	sf::Texture settings_t;

	sf::Sprite exit_s;
	sf::Texture exit_t;

	sf::Sprite map_s;
	sf::Texture map_t;

	MenuStateBase* state_;

};

#endif