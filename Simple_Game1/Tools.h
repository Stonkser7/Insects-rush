#ifndef TOOLS_H
#define TOOLS_H

#include <SFML/Graphics.hpp>

namespace tool {

	float magnitude(const sf::Vector2f& vec);


	sf::Vector2f normalized(sf::Vector2f vec);

}

#endif