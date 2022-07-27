#pragma once
#include <SFML/Graphics.hpp>
#include "Tools.h"




class Player
{
	sf::Sprite sprite;
	sf::Texture texture;

	sf::Vector2f moveDir;
	float speed;


	

public:
	Player() = delete;
	Player(const Player&) = delete;

	Player(std::string texture_file, sf::Vector2f spawnPos);

	enum class DIR { UP, DOWN, LEFT, RIGHT };


	sf::Vector2f getPos() const;
	sf::Vector2f getMoveDir() const;

	void addMoveDir(DIR dir);

	void rotateTo(sf::Vector2i point);


	void updatePos(float deltaT);

	void unsetMoveDir();

	float getSpeed() const;

	sf::Sprite drawable() const;


};

