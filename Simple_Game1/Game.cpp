#include "Game.h"



void Game::run()
{
	InputHandler inputHandler;
	Player player;


	while (true) {
		inputHandler.handleInput(player);

	}

}
