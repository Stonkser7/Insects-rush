#include "MainMenuData.h"

void DATA::MainMenuData::load()
{
	background.loadFromFile("Sprites\\Menu\\background.jpg");
	play_button.loadFromFile("Sprites\\Menu\\UI_sheet.png", sf::IntRect(5, 4, 63, 63));
	settings_button.loadFromFile("Sprites\\Menu\\UI_sheet.png", sf::IntRect(84, 4, 63, 63));
	exit_button.loadFromFile("Sprites\\Menu\\UI_sheet.png", sf::IntRect(162, 4, 63, 63));
	selected_mark.loadFromFile("Sprites\\basePlayer.png");

}
