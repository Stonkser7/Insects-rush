#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Assets.h"
#include "Player.h"
#include "Camera.h"
#include "Surface.h"
#include <string>



class Game
{
public:
	Game();
	void run();


private:
	Camera cam_;
	Surface surface_;
	Player player_;

	void handleInput();
	void update();
	void render();

	const float MS_PER_UPDATE_;

	sf::RenderWindow window_;
};

#endif