#include "PlayerWalkState.h"

//FOR TESTS
#include <iostream>



void PlayerWalkState::init(Player& player)
{
	speed_ = 6;

	legs_.setPosition(player.getPos());

	animation_.setAnim(&Assets::getAssets().player_walk);
}

PlayerState* PlayerWalkState::handleInput(Player& player)
{
	bool isMoving = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		addDirUp();
		isMoving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		addDirDown();
		isMoving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		addDirLeft();
		isMoving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		addDirRight();
		isMoving = true;
	}

	if (!isMoving) {
		return new PlayerIdleState;
	}
	else {
		return nullptr;
	}
}

void PlayerWalkState::update(Player& player, float elapsed_time)
{
	sf::Vector2f direction = tool::normalized(move_dir_);
	player.move(direction * speed_);

	animation_.update(elapsed_time);
	animation_.toSprite(legs_);

	legs_.setPosition(player.getPos());
	legs_.setRotation(std::atan2(direction.x, -direction.y) * 180 / 3.14);
	std::cout << legs_.getPosition().x + direction.x << " -- " << legs_.getPosition().y + direction.y << std::endl;

	move_dir_.x = 0;
	move_dir_.y = 0;
}

void PlayerWalkState::render(Player& player, sf::RenderWindow& win)
{
	win.draw(legs_);
}



void PlayerWalkState::addDirUp()
{
	move_dir_.y -= 1;
}

void PlayerWalkState::addDirDown()
{
	move_dir_.y += 1;
}

void PlayerWalkState::addDirLeft()
{
	move_dir_.x -= 1;
}

void PlayerWalkState::addDirRight()
{
	move_dir_.x += 1;
}