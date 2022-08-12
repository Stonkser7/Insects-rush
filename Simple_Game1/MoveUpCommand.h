#ifndef MOVE_UP_COMMAND_H
#define MOVE_UP_COMMAND_H

#include <SFML/Graphics.hpp>
#include "Command.h"
#include "Player.h"

class MoveUpCommand : public Command
{
public:
	MoveUpCommand(sf::Keyboard::Key key);
	void execute(Player& player) override;
};

#endif