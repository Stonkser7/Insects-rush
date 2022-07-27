#include "MenuItem.h"


MenuItem::MenuItem(sf::Texture& t, GAMESTATE act)
{
	sprite.setTexture(t);
	action = act;
}

void MenuItem::setPos(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}

void MenuItem::setPos(float x, float y)
{
	sprite.setPosition(x, y);
}

bool MenuItem::isCollisionWith(sf::Vector2f& point) const
{
	return sprite.getGlobalBounds().contains(point);
}

bool MenuItem::isCollisionWith(float x, float y) const
{
	return sprite.getGlobalBounds().contains(x, y);
}

void MenuItem::select()
{
	is_selected = true;
}

void MenuItem::unselect()
{
	is_selected = false;
}

bool MenuItem::selected() const
{
	return is_selected;
}


GAMESTATE MenuItem::operator()()
{
	return action;
}

sf::Sprite& MenuItem::getSprite()
{
	return sprite;
}

