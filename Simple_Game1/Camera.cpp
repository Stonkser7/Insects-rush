#include "Camera.h"

Camera::Camera(float speed, sf::Vector2f view = sf::Vector2f()) : speed_(speed)
{
	view_.setCenter(view);
}

Camera::Camera(float speed, sf::View view) : speed_(speed)
{
	view_ = view;
}

void Camera::follow(sf::Vector2f point)
{
	sf::Vector2f offset = point - view_.getCenter();
	float distance = tool::magnitude(offset);
	sf::Vector2f move_dir = tool::normalized(offset);
	view_.move((distance / MAX_DISTANCE) * speed_ * move_dir);
}

const sf::View& Camera::operator()()
{
	return view_;
}