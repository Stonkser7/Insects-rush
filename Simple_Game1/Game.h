#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Camera.h"
#include "Surface.h"
#include <string>



class Game
{
public:
	Game();
	void run();

	static const float& MS_PER_UPDATE();

private:
	Camera cam_;
	Surface surface_;
	Player player_;

	void handleInput();
	void update();
	void render();


	static const float MS_PER_UPDATE_;
	
	sf::RenderWindow window_;
};

#endif