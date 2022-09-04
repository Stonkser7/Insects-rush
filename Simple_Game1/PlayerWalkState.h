#ifndef PLAYER_WALK_STATE
#define PLAYER_WALK_STATE

#include <SFML/Graphics.hpp>
#include "PlayerState.h"
#include "PlayerIdleState.h"
#include "Assets.h"
#include "Player.h"


class PlayerWalkState : public PlayerState
{
public:
	void init(Player& player) override;
	PlayerState* handleInput(Player& player) override;
	void update(Player& player, float elapsed_time) override;
	void render(Player& player, sf::RenderWindow& win) override;

private:
	void addDirUp();
	void addDirDown();
	void addDirLeft();
	void addDirRight();

	sf::Vector2f move_dir_;	//becomes normalized when update()
	float speed_;

	sf::Sprite legs_;

	AnimationComponent animation_;
};

#endif