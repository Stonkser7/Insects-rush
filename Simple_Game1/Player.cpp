#include "Player.h"


Player::Player(std::string textureFile)
{
	texture.loadFromFile(textureFile);

}

void Player::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

sf::Sprite Player::drawable()
{
	return sprite;
}
