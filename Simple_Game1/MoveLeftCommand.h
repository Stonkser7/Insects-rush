#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H

#include <SFML/Graphics.hpp>
#include "Command.h"
#include "Player.h"

class MoveLeftCommand : public Command
{
public:
	MoveLeftCommand(sf::Keyboard::Key key);
	void execute(Player& player) override;
};

#endif