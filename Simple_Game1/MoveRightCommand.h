#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H

#include <SFML/Graphics.hpp>
#include "Command.h"

class MoveRightCommand : public Command
{
public:
	MoveRightCommand(sf::Keyboard::Key key);
	void execute(Player& player) override;
};

#endif