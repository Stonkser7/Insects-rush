#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Command.h"
#include "MoveUpCommand.h"
#include "MoveDownCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "Player.h"

class InputHandler
{
public:
	InputHandler();

	void handleInput(Player& player);

	~InputHandler();

private:
	void addCommand(Command* command);
	std::vector<Command*> commands_;
};

#endif