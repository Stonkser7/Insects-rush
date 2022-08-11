#include "Player.h"

Player::Player(): speed_(10)
{
	t_.loadFromFile("Sprites\\basePlayer.png");
	s_.setTexture(t_);
}

void Player::addDirUp()
{
	move_dir_.y -= 1;
}

void Player::addDirDown()
{
	move_dir_.y += 1;
}

void Player::addDirLeft()
{
	move_dir_.x -= 1;
}

void Player::addDirRight()
{
	move_dir_.x += 1;
}

void Player::update()
{
	sf::Vector2f direction = tool::normalized(move_dir_);
	s_.move(direction * speed_);
	move_dir_.x = 0;
	move_dir_.y = 0;
}

const sf::Sprite& Player::sprite() const
{
	return s_;
}
