#include "AnimationFrame.h"

AnimationFrame::AnimationFrame(const std::string& file, const sf::IntRect& rect, float delay) : delay_(delay)
{
	t_.loadFromFile(file, rect);
}
