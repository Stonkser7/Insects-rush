#include "MoveDownCommand.h"

MoveDownCommand::MoveDownCommand(sf::Keyboard::Key key)
{
	key_ = key;
}

void MoveDownCommand::execute(Player& player)
{
	player.addDirDown();
}
