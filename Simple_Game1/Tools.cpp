#include "Tools.h"



float tool::magnitude(const sf::Vector2f& vec)
{
	return std::sqrtf(std::powf(vec.x, 2) + std::powf(vec.y, 2));
}

sf::Vector2f tool::normalized(sf::Vector2f vec)
{
	float length = tool::magnitude(vec);

	if (length == 0) {
		vec.x = 0;
		vec.y = 0;
		return vec;
	}

	vec.x = vec.x / length;
	vec.y = vec.y / length;


	return vec;
}