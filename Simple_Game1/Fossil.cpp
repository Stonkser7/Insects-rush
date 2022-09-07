#include "Fossil.h"

//FOR TESTS


void Fossil::init(sf::Vector2f pos)
{
	sprite_.setTexture(Assets::getAssets().fossil_base);
	sprite_.setPosition(pos);
}

void Fossil::render(sf::RenderWindow& win) const
{
	win.draw(sprite_);
}

