#include "PlayerIdleState.h"

void PlayerIdleState::init(Player& player)
{

}

PlayerState* PlayerIdleState::handleInput(Player& player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		return new PlayerWalkState;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		return new PlayerWalkState;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		return new PlayerWalkState;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		return new PlayerWalkState;
	}

	return nullptr;
}

void PlayerIdleState::update(Player& player, float elapsed_time)
{
}

void PlayerIdleState::render(Player& player, sf::RenderWindow& win)
{
}
