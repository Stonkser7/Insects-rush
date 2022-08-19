#ifndef SURFACE_H
#define SURFACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Surface
{
public:
	void init(const std::string& texture_file, sf::Vector2f sectors_size);

	~Surface();
	
	void update(const sf::View& view);

	void render(sf::RenderWindow& win);

private:

	sf::Texture t_;

	std::vector<sf::RectangleShape*> sectors_;

	sf::Vector2f* sector_size_;

	bool isEmptyHere(sf::Vector2f Where);

	void addSector(sf::Vector2f here);
};
#endif