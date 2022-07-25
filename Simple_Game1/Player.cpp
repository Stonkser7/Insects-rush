#include "Player.h"


Player::Player(std::string texture_file)
{
	texture.loadFromFile(texture_file);
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	speed = 100;		//per second
	moveDir.x = 0;
	moveDir.y = 0;
}


void Player::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

sf::Vector2f Player::getPos() const
{
	return sprite.getPosition();
}

sf::Vector2f Player::getMoveDir() const
{
	return moveDir;
}


void Player::addMoveDir(DIR dir)
{
	switch (dir) {
	case DIR::UP:
		--moveDir.y;
		break;
	case DIR::DOWN:
		++moveDir.y;
		break;
	case DIR::LEFT:
		--moveDir.x;
		break;
	case DIR::RIGHT:
		++moveDir.x;
		break;
	}
}

void Player::rotateTo(sf::Vector2i point)
{
	sprite.setRotation(std::atan2(point.y - getPos().y, point.x - getPos().x) * 180 / 3.1415 + 90);
}




void Player::updatePos(float deltaT)
{
	sprite.move(tool::normalized(moveDir).x * speed * deltaT, tool::normalized(moveDir).y * speed * deltaT);
	unsetMoveDir();
}

void Player::unsetMoveDir()
{
	moveDir.x = 0;
	moveDir.y = 0;
}



float Player::getSpeed() const
{
	return speed;
}



sf::Sprite Player::drawable() const
{
	return sprite;
}
