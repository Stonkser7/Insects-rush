#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include "Tools.h"

class Camera
{
public:
	void init(sf::View view);

	void follow(sf::Vector2f point);

	const sf::View& operator()();

private:

	sf::View view_;

	const float MAX_DISTANCE = 20;
};

#endif