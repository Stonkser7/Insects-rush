#ifndef ANIMATION_FRAME
#define ANIMATION_FRAME

#include <SFML/Graphics.hpp>

class AnimationFrame
{
public:
	AnimationFrame(const std::string& file, const sf::IntRect& rect, float delay);
private:
	sf::Texture t_;
	float delay_;
};

#endif