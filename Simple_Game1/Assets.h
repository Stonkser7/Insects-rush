#ifndef ASSETS
#define ASSETS

#include "Animation.h"
#include <SFML/Graphics.hpp>

class Assets
{
public:
	static Assets& getAssets();

	void init();

	Animation player_walk;
	sf::Texture player_base;

private:
	Assets() {};
};

#endif