#include "Camera.h"



void Camera::init(sf::View view)
{
	view_ = view;
}

void Camera::follow(sf::Vector2f point)
{
	sf::Vector2f offset = point - view_.getCenter();
	float distance = tool::magnitude(offset);
	sf::Vector2f move_dir = tool::normalized(offset);
	view_.move((distance / MAX_DISTANCE) * move_dir);
}

const sf::View& Camera::operator()()
{
	return view_;
}