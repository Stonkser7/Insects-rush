#include "Assets.h"

void Assets::init()
{
	//Player//
	//////////
	//walk
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(11, 67, 34, 18), 40, { 17, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(75, 30, 34, 54), 100, { 17, 45 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(139, 9, 35, 85), 100, { 18, 66 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(199, 22, 38, 82), 120, { 21, 53 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(263, 34, 38, 79), 120, { 21, 41 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(327, 66, 38, 38), 80, { 21, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(395, 66, 34, 18), 40, { 17, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(459, 30, 34, 54), 100, { 17, 45 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(523, 9, 35, 85), 100, { 17, 66 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(587, 22, 38, 82), 120, { 17, 53 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(651, 34, 38, 79), 120, { 17, 41 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(715, 66, 38, 38), 80, { 17, 9 });




}

Assets& Assets::getAssets()
{
	static Assets* instance = new Assets;
	return *instance;
}


