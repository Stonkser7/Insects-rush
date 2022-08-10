#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "MenuStateBase.h"
#include <SFML/Graphics.hpp>

class MainMenuState : public MenuStateBase
{
public:
	bool isOnButton(sf::Sprite button, sf::Vector2i point);
private:
	MenuStateBase* processInputs(Menu& menu, Game& game) override;
	void update(Menu& menu, Game& game) override;
	void render(Menu& menu, Game& game) override;
};

#endif