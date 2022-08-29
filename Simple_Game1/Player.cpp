#include "Player.h"

void Player::init()
{
	t_.loadFromFile("Sprites\\test\\basePlayer.png");
	s_.setTexture(t_);

	//s_.setOrigin(s_.getLocalBounds().width / 2, s_.getLocalBounds().height / 2);
	s_.setOrigin(31, 73);

	s_.setPosition(960, 540);

	speed_ = 7;
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

void Player::lookAt(sf::Vector2i point)
{
	s_.setRotation(std::atan2(s_.getPosition().y - point.y, s_.getPosition().x - point.x) * 180 / 3.14 - 90);
}


void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		addDirUp();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		addDirDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		addDirLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		addDirRight();
	}
}

void Player::update()
{
	sf::Vector2f direction = tool::normalized(move_dir_);
	s_.move(direction * speed_);
	move_dir_.x = 0;
	move_dir_.y = 0;
}

void Player::render(sf::RenderWindow& win)
{
	win.draw(s_);


}

const sf::Sprite& Player::sprite() const
{
	return s_;
}
