#include "Player.h"

Player::Player(): speed_(7)
{
	t_.loadFromFile("Sprites\\basePlayer.png");
	s_.setTexture(t_);

	s_.setOrigin(s_.getLocalBounds().width / 2, s_.getLocalBounds().height / 2);

	s_.setPosition(500, 400);

	addCommand(new MoveUpCommand(sf::Keyboard::Key::W));
	addCommand(new MoveDownCommand(sf::Keyboard::Key::S));
	addCommand(new MoveLeftCommand(sf::Keyboard::Key::A));
	addCommand(new MoveRightCommand(sf::Keyboard::Key::D));
}

Player::~Player()
{
	for (auto x : commands_) {
		delete x;
	}
}

void Player::addCommand(Command* command)
{
	commands_.push_back(command);
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
	for (auto x : commands_) {
		if (sf::Keyboard::isKeyPressed(x->getKey())) {
			x->execute(*this);
		}
	}
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
