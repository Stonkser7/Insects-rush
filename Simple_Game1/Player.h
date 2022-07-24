#pragma once
#include <SFML/Graphics.hpp>




class Player
{
	sf::Sprite sprite;
	sf::Texture texture;

public:
	Player() = delete;
	Player(const Player&) = delete;



	Player(std::string textureFile);
	void setPos(sf::Vector2f pos);
	sf::Sprite drawable();


};

