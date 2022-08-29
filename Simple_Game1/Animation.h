#ifndef ANIMATION
#define ANIMATION

#include <vector>
#include "AnimationFrame.h"
#include <SFML/Graphics.hpp>

class Animation
{
public:
	const AnimationFrame& getFrame(int num) const;

	void addFrame(const std::string& file, const sf::IntRect& rect, float delay);

private:
	std::vector<AnimationFrame> frames_;
};

#endif