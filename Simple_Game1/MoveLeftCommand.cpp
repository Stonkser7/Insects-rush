#include "MoveLeftCommand.h"

MoveLeftCommand::MoveLeftCommand(sf::Keyboard::Key key)
{
	key_ = key;
}

void MoveLeftCommand::execute(Player& player)
{
	player.addDirLeft();
}
