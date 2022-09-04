#include "Player.h"

void Player::init()
{
	body_.setTexture(Assets::getAssets().player_base);

	body_.setOrigin(24, 66);

	body_.setPosition(960, 540);

	state_ = new PlayerIdleState;
	state_->init(*this);
}


void Player::lookAt(sf::Vector2i point)
{
	body_.setRotation(std::atan2(body_.getPosition().y - point.y, body_.getPosition().x - point.x) * 180 / 3.14 - 90);
}

void Player::move(sf::Vector2f offset)
{
	body_.move(offset);
}

sf::Vector2f Player::getPos() const
{
	return body_.getPosition();
}


void Player::handleInput()
{

	PlayerState* new_state = state_->handleInput(*this);

	if (new_state) {
		delete state_;
		state_ = new_state;
		state_->init(*this);
	}
}

void Player::update(float elapsed_time)
{
	state_->update(*this, elapsed_time);
}

void Player::render(sf::RenderWindow& win)
{
	state_->render(*this, win);
	win.draw(body_);
}