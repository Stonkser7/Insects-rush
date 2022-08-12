#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Tools.h"
#include <SFML/Graphics.hpp>
#include "MoveUpCommand.h"
#include "MoveDownCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"

class Player
{
public:
	Player();
	~Player();
	void addCommand(Command* command);
	void addDirUp();
	void addDirDown();
	void addDirLeft();
	void addDirRight();
	void lookAt(sf::Vector2i point);

	void handleInput();

	void update();
	const sf::Sprite& sprite() const;
private:

	sf::Texture t_;
	sf::Sprite s_;

	sf::Vector2f move_dir_;	//becomes normalized when update()
	float speed_;

	std::vector<Command*> commands_;
};

#endif