#ifndef ANIMATION_FRAME
#define ANIMATION_FRAME

#include <SFML/Graphics.hpp>

class AnimationFrame
{
public:
	AnimationFrame() = delete;

	AnimationFrame(const std::string& file, const sf::IntRect& rect, float duration, sf::Vector2f origin);
	float getDuration() const;
	const sf::Texture& getTexture() const;
	sf::Vector2f getOrigin() const;
private:
	sf::Texture t_;
	float duration_;
	sf::Vector2f origin_;
};

#endif