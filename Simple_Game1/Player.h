#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Tools.h"
#include <SFML/Graphics.hpp>
#include "AnimationComponent.h"
#include "Assets.h"

class Player
{
public:
	void init();

	void addDirUp();
	void addDirDown();
	void addDirLeft();
	void addDirRight();
	void lookAt(sf::Vector2i point);
	sf::Vector2f getPos() const;

	void handleInput();
	void update(float elapsed_time);
	void render(sf::RenderWindow& win);
private:

	sf::Texture t_;
	sf::Sprite body_;

	sf::Sprite legs_;

	sf::Vector2f move_dir_;	//becomes normalized when update()
	float speed_;

	AnimationComponent animation_;

};

#endif