#ifndef PLAYER_STATE
#define PLAYER_STATE

#include <SFML/Graphics.hpp>

class Player;

class PlayerState
{
public:
	virtual void init(Player& player) = 0;
	virtual PlayerState* handleInput(Player& player) = 0;
	virtual void update(Player& player, float elapsed_time) = 0;
	virtual void render(Player& player, sf::RenderWindow& win) = 0;
private:

};

#endif