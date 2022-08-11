#include "MoveRightCommand.h"

MoveRightCommand::MoveRightCommand(sf::Keyboard::Key key)
{
	key_ = key;
}

void MoveRightCommand::execute(Player& player)
{
	player.addDirRight();
}
