#ifndef FOSSILS_MANAGER
#define FOSSILS_MANAGER

#include <SFML/Graphics.hpp>
#include "Fossil.h"
#include "Tools.h"
#include <random>
#include <vector>


class FossilsManager
{
public:
	void randSpawn(sf::Vector2f around, float max_distance);

	void renderFossils(sf::RenderWindow& win);

private:
	std::vector<Fossil> fossils_;
};

#endif