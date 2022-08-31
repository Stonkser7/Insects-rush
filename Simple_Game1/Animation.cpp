#include "Animation.h"

const AnimationFrame& Animation::getFrame(int num) const
{
	return frames_[num];
}

void Animation::addFrame(const std::string& file, const sf::IntRect& rect, float duration, sf::Vector2f origin)
{
	AnimationFrame newFrame(file, rect, duration, origin);
	frames_.push_back(newFrame);
}

int Animation::numberOfFrames() const
{
	return frames_.size();
}
