#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Tools.h"
#include <SFML/Graphics.hpp>
#include "AnimationComponent.h"
#include "Assets.h"
#include "PlayerIdleState.h"

class Player
{
public:
	void init();

	void lookAt(sf::Vector2i point);
	void move(sf::Vector2f offset);
	sf::Vector2f getPos() const;


	void handleInput();
	void update(float elapsed_time);
	void render(sf::RenderWindow& win);
private:
	sf::Sprite body_;

	PlayerState* state_;
};

#endif