#ifndef ANIMATION
#define ANIMATION

#include <vector>
#include "AnimationFrame.h"
#include <SFML/Graphics.hpp>

class Animation
{
public:

	void addFrame(const std::string& file, const sf::IntRect& rect, float duration, sf::Vector2f origin);

	const AnimationFrame& getFrame(int num) const;

	int numberOfFrames() const;

private:
	std::vector<AnimationFrame> frames_;
};

#endif