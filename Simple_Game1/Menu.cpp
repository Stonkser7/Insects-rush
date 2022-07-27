#include "Menu.h"

#include <iostream>


///////////////////////////////////////////////////////////////////////////////////////////////////
//private:
//////////

void Menu::init()
{
	background.setTexture(data.background);
	selecting_mark.setTexture(data.selected_mark);
	selecting_mark.setOrigin(selecting_mark.getLocalBounds().width / 2, selecting_mark.getLocalBounds().height / 2);
	addMenuItem(data.play_button, GAMESTATE::PLAY);
	addMenuItem(data.settings_button, GAMESTATE::SETTINGS);
	addMenuItem(data.exit_button, GAMESTATE::EXIT);
	buttons_indent_x = 100;
}


void Menu::addMenuItem(sf::Texture& t, GAMESTATE action)
{
	MenuItem new_item(t, action);
	buttons.push_back(new_item);
}

void Menu::adjust_buttons()
//deploys menu buttons on the screen
{
	if (!buttons.empty()) {
		float ui_size = 0;		//x size of menu UI area
		for (MenuItem& i : buttons) {
			ui_size += i.getSprite().getGlobalBounds().width;
		}
		ui_size += (buttons.size() - 1) * buttons_indent_x;

		for (int i = 0; i < buttons.size(); ++i) {
			if (i == 0) {
				buttons[i].setPos((window->getSize().x - ui_size) / 2, window->getSize().y / 2);
			}
			else {
				buttons[i].setPos(buttons[i - 1].getSprite().getPosition().x + buttons[i - 1].getSprite().getGlobalBounds().width + buttons_indent_x, buttons[i - 1].getSprite().getPosition().y);
			}
		}
	}

}

void Menu::checkForSelect()
{
	sf::Vector2f mouse = { static_cast<float>(sf::Mouse::getPosition(*window).x), static_cast<float>(sf::Mouse::getPosition(*window).y) };
	for (auto& b : buttons) {
		if (b.isCollisionWith(mouse)) {
			b.select();
		}
		else {
			b.unselect();
		}
	}
}

void Menu::draw_frame()
{
	window->clear();

	window->draw(background);
	sf::Vector2f mouse = { static_cast<float>(sf::Mouse::getPosition(*window).x), static_cast<float>(sf::Mouse::getPosition(*window).y) };
	for (auto& b : buttons) {
		if (b.selected()) {
			selecting_mark.setPosition(mouse.x, mouse.y + buttons_indent_x * 2);
			window->draw(selecting_mark);
		}
		window->draw(b.getSprite());
	}

	window->display();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//public:
/////////
Menu::Menu(sf::RenderWindow* win)
{
	window = win;
	data.load();
	init();
	adjust_buttons();
}




GAMESTATE Menu::run()
{

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			}

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			for (auto& b : buttons) {
				if (b.selected()) return b();
			}
		}

		checkForSelect();

		draw_frame();
	}

	return GAMESTATE::EXIT;
}
