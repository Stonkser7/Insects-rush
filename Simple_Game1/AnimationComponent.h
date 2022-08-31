#ifndef ANIMATION_COMPONENT
#define ANIMATION_COMPONENT

#include "Animation.h"
#include <SFML/Graphics.hpp>

class AnimationComponent
{
public:

	void update(float elapsed_time);

	void setAnim(Animation* new_anim, int current_frame = 0);

	void toSprite(sf::Sprite& target);

private:
	Animation* anim_;
	int current_frame_;
	float timer_;
};

#endif