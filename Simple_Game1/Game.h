#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"



class Game
{
public:
	Game();
	void run();

private:
	const float MS_PER_UPDATE = 16;
	sf::RenderWindow window_;
};


#endif