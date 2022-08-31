#include "Player.h"

void Player::init()
{
	t_.loadFromFile("Sprites\\test\\basePlayer.png");

	body_.setTexture(t_);

	body_.setOrigin(31, 74);

	body_.setPosition(960, 540);

	legs_.setPosition(body_.getPosition());

	speed_ = 7;

	animation_.setAnim(&Assets::getAssets().player_walk);
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
	body_.setRotation(std::atan2(body_.getPosition().y - point.y, body_.getPosition().x - point.x) * 180 / 3.14 - 90);
	legs_.setRotation(std::atan2(body_.getPosition().y - point.y, body_.getPosition().x - point.x) * 180 / 3.14 - 90);
}

sf::Vector2f Player::getPos() const
{
	return body_.getPosition();
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

void Player::update(float elapsed_time)
{
	sf::Vector2f direction = tool::normalized(move_dir_);
	body_.move(direction * speed_);

	legs_.setPosition(body_.getPosition());


	animation_.update(elapsed_time);
	animation_.toSprite(legs_);

	move_dir_.x = 0;
	move_dir_.y = 0;
}

void Player::render(sf::RenderWindow& win)
{
	win.draw(legs_);
	win.draw(body_);
}