#ifndef FOSSIL
#define FOSSIL

#include <SFML/Graphics.hpp>
#include "Assets.h"

class Fossil
{
public:
	void init(sf::Vector2f pos);

	void render(sf::RenderWindow& win) const;

private:
	sf::Sprite sprite_;

	//bool isBuried_;
};

#endif