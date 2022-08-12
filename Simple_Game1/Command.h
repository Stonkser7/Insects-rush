#ifndef COMMAND_H
#define COMMAND_H

#include <SFML/Graphics.hpp>

class Player;
//base class
class Command
{
public:
	virtual void execute(Player&) = 0;
	sf::Keyboard::Key getKey();
protected:
	sf::Keyboard::Key key_;
};
#endif