#include "Assets.h"

void Assets::init()
{
	//Player//
	//////////
	//walk
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(11, 67, 34, 18), 22.4, { 17, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(75, 30, 34, 54), 56, { 17, 45 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(139, 9, 35, 85), 56, { 18, 66 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(199, 22, 38, 82), 67.2, { 21, 53 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(263, 34, 38, 79), 67.2, { 21, 41 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(327, 66, 38, 38), 44.8, { 21, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(395, 66, 34, 18), 22.4, { 17, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(459, 30, 34, 54), 56, { 17, 45 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(523, 9, 35, 85), 56, { 17, 66 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(587, 22, 38, 82), 67.2, { 17, 53 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(651, 34, 38, 79), 67.2, { 17, 41 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(715, 66, 38, 38), 44.8, { 17, 9 });

	/*player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(11, 67, 34, 18), 32, { 17, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(75, 30, 34, 54), 80, { 17, 45 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(139, 9, 35, 85), 80, { 18, 66 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(199, 22, 38, 82), 96, { 21, 53 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(263, 34, 38, 79), 96, { 21, 41 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(327, 66, 38, 38), 64, { 21, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(395, 66, 34, 18), 32, { 17, 9 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(459, 30, 34, 54), 80, { 17, 45 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(523, 9, 35, 85), 80, { 17, 66 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(587, 22, 38, 82), 96, { 17, 53 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(651, 34, 38, 79), 96, { 17, 41 });
	player_walk.addFrame("Sprites\\test\\player_legs_anim.png", sf::IntRect(715, 66, 38, 38), 64, { 17, 9 });*/

	player_base.loadFromFile("Sprites\\test\\basePlayer.png");


}

Assets& Assets::getAssets()
{
	static Assets* instance = new Assets;
	return *instance;
}


