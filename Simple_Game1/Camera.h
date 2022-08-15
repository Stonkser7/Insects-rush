#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include "Tools.h"

class Camera
{
public:
	Camera() = delete;
	Camera(float speed, sf::Vector2f view);
	Camera(float speed, sf::View view);

	void follow(sf::Vector2f point);

	const sf::View& operator()();

private:

	sf::View view_;

	float speed_;
	const float MAX_DISTANCE = 1500;
};

#endif