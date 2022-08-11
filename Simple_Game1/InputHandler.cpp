#include "InputHandler.h"

InputHandler::InputHandler()
{
	addCommand(new MoveUpCommand(sf::Keyboard::Key::W));
	addCommand(new MoveDownCommand(sf::Keyboard::Key::S));
	addCommand(new MoveLeftCommand(sf::Keyboard::Key::A));
	addCommand(new MoveRightCommand(sf::Keyboard::Key::D));
}

void InputHandler::addCommand(Command* command)
{
	commands_.push_back(command);
}

void InputHandler::handleInput(Player& player)
{
	for (auto x : commands_) {
		if (sf::Keyboard::isKeyPressed(x->getKey())) {
			x->execute(player);
		}
	}
}

InputHandler::~InputHandler()
{
	for (auto x : commands_) {
		delete x;
	}
}
