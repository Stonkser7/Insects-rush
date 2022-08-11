#ifndef MOVE_DOWN_COMMAND_H
#define MOVE_DOWN_COMMAND_H

#include <SFML/Graphics.hpp>
#include "Command.h"

class MoveDownCommand : public Command
{
public:
	MoveDownCommand(sf::Keyboard::Key key);
	void execute(Player& player) override;
};

#endif