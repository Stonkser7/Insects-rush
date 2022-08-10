#include "MainMenuState.h"

bool MainMenuState::isOnButton(sf::Sprite button, sf::Vector2i point)
{
	return button.getGlobalBounds().contains(point.x, point.y);
}

MenuStateBase* MainMenuState::processInputs(Menu& menu, Game& game)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		sf::Vector2i mouse = sf::Mouse::getPosition(menu.game_.window_);

		if (isOnButton(menu.selectButton(), mouse)) {
			return ; //SelectMenuState
		}

		if (isOnButton(menu.settingsButton(), mouse)) {
			return ; //SettingsMenuState
		}

		if (isOnButton(menu.exitButton(), mouse)) {
			return ; //ToExitMenuState
		}
	}


	return nullptr;
}

void MainMenuState::update(Menu& menu, Game& game)
{


}

void MainMenuState::render(Menu& menu, Game& game)
{
	game.window_.clear();

	game.window_.draw(menu.selectButton());
	game.window_.draw(menu.settingsButton());
	game.window_.draw(menu.exitButton());

	game.window_.display();
}
