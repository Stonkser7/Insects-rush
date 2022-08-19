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

private:
	Camera cam_;
	Surface surface_;
	Player player_;
	std::vector<Command*> commands_;

	void handleInput();
	void update();
	void render();



	const float MS_PER_UPDATE = 16;
	sf::Clock frame_timer;
	float current;
	float lag;
	sf::RenderWindow window_;
};


#endif