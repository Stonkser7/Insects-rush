#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Game.h"


void error(std::string s1, std::string s2 = "")
{
	throw std::runtime_error(s1 + s2);
}




int main()
{

	Game IR;

	IR.run();



}