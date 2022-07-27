#pragma once

#include <SFML/Graphics.hpp>


namespace DATA {
	struct MainMenuData {
		sf::Texture background;
		sf::Texture play_button;
		sf::Texture settings_button;
		sf::Texture exit_button;
		sf::Texture selected_mark;

		void load();
	};
}