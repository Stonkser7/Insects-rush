#include "Menu.h"

Menu::Menu(Game& game, MenuStateBase* state = new MainMenuState) : game_(game), state_(state)
{
	select_level_t.loadFromFile("Sprites\\Menu\\UI_sheet.png", sf::IntRect(5, 4, 63, 63));
	select_level_s.setTexture(select_level_t);

	settings_t.loadFromFile("Sprites\\Menu\\UI_sheet.png", sf::IntRect(84, 4, 63, 63));
	settings_s.setTexture(settings_t);

	exit_t.loadFromFile("Sprites\\Menu\\UI_sheet.png", sf::IntRect(162, 4, 63, 63));
	exit_s.setTexture(exit_t);
}




void Menu::run()
{
	while (true) {//<-- game.state != play || game.state != exit or run() returns MenuReturnState::GameState or menu state that changes game state

		MenuStateBase* state = state_->processInputs(*this, game_);

		state_->update(*this, game_);

		state_->render(*this, game_);


		if (state) {
			delete state_;
			state_ = state;
		}
	}

}

const sf::Sprite& Menu::selectButton() const
{
	return select_level_s;
}

const sf::Sprite& Menu::settingsButton() const
{
	return settings_s;
}

const sf::Sprite& Menu::exitButton() const
{
	return exit_s;
}

Menu::~Menu()
{

	delete state_;

}
