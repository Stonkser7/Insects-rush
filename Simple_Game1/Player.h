#ifndef PLAYER_H
#define PLAYER_H

#include "Tools.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void addDirUp();
	void addDirDown();
	void addDirLeft();
	void addDirRight();

	void update();
	const sf::Sprite& sprite() const;
private:

	sf::Texture t_;
	sf::Sprite s_;

	sf::Vector2f move_dir_;	//becomes normalized when update()
	float speed_;
};

#endif