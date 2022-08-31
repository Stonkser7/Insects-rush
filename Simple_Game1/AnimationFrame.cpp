#include "AnimationFrame.h"

AnimationFrame::AnimationFrame(const std::string& file, const sf::IntRect& rect, float delay, sf::Vector2f origin) : duration_(delay), origin_(origin)
{
	t_.loadFromFile(file, rect);
}

float AnimationFrame::getDuration() const
{
	return duration_;
}

const sf::Texture& AnimationFrame::getTexture() const
{
	return t_;
}

sf::Vector2f AnimationFrame::getOrigin() const
{
	return origin_;
}
