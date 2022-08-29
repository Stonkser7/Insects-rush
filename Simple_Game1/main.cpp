#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Game.h"


void error(std::string s1, std::string s2 = "")
{
	throw std::runtime_error(s1 + s2);
}


const float Game::MS_PER_UPDATE_ = 16;

int main()
{

	Game IR;

	IR.run();



}