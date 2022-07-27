#include "Game.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//private:
//////////
void Game::initData()
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//public:
/////////
Game::Game(sf::RenderWindow* win) : window{ win }
{
	initData();
	state = GAMESTATE::MENU;
}

GAMESTATE Game::getState() const
{
	return state;
}

void Game::menu()
{
	Menu menu(window);

	state = menu.run();

}

//void Game::play()
//{
//	window->setFramerateLimit(60);
//
//	Player p("Sprites\\basePlayer.png", sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
//}
