#ifndef PLAYER_IDLE_STATE
#define PLAYER_IDLE_STATE

#include "PlayerState.h"
#include "PlayerWalkState.h"

class PlayerIdleState : public PlayerState
{
public:
	void init(Player& player) override;
	PlayerState* handleInput(Player& player) override;
	void update(Player& player, float elapsed_time) override;
	void render(Player& player, sf::RenderWindow& win) override;
private:
};

#endif