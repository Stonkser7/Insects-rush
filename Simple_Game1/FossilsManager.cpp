#include "FossilsManager.h"


//FOR TESTS
#include <iostream>

void FossilsManager::randSpawn(sf::Vector2f around, float max_distance)
{
	std::random_device rd;
	std::mt19937 generator(rd());

	std::uniform_real_distribution<float> rand_direction(-1, 1);
	std::uniform_real_distribution<float> rand_distance(0, max_distance);


	sf::Vector2f direction(rand_direction(generator), rand_direction(generator));
	direction = tool::normalized(direction);

	float distance = rand_distance(generator);

	Fossil new_fossil;
	new_fossil.init(around + (direction * distance));
	fossils_.push_back(new_fossil);

	//std::cout << distance << std::endl;
}

void FossilsManager::renderFossils(sf::RenderWindow& win)
{
	for (const Fossil& f : fossils_) {
		f.render(win);
	}
}
