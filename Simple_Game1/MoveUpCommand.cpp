#include "MoveUpCommand.h"


MoveUpCommand::MoveUpCommand(sf::Keyboard::Key key)
{
	key_ = key;
}

void MoveUpCommand::execute(Player& player)
{
	player.addDirUp();
}
