#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

class MenuItem
{
	sf::Sprite sprite;
	GAMESTATE action;
	bool is_selected;

public:
	MenuItem() = delete;

	MenuItem(sf::Texture& t, GAMESTATE act);

	void setPos(const sf::Vector2f& pos);
	void setPos(float x , float y);

	bool isCollisionWith(sf::Vector2f& point) const;	//collision with mouse, for example
	bool isCollisionWith(float x, float y) const;

	void select();
	void unselect();
	bool selected() const;

	GAMESTATE operator()();

	sf::Sprite& getSprite();
};

