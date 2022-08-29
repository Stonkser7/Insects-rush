#include "Animation.h"

const AnimationFrame& Animation::getFrame(int num) const
{
	return frames_[num];
}

void Animation::addFrame(const std::string& file, const sf::IntRect& rect, float delay)
{
	AnimationFrame newFrame(file, rect, delay);
	frames_.push_back(newFrame);
}
