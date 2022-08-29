#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Tools.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	void init();

	void addDirUp();
	void addDirDown();
	void addDirLeft();
	void addDirRight();
	void lookAt(sf::Vector2i point);

	void handleInput();
	void update();
	void render(sf::RenderWindow& win);
private:

	sf::Texture t_;
	sf::Sprite s_;

	sf::Vector2f move_dir_;	//becomes normalized when update()
	float speed_;


};

#endif