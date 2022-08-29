#ifndef ANIMATION_COMPONENT
#define ANIMATION_COMPONENT

#include "Animation.h"
#include <SFML/Graphics.hpp>

class AnimationComponent
{
public:


	void update(sf::Sprite& sprite, float elapsed_time);

	void setAnim(Animation* newAnim);

private:
	Animation* anim_;
};

#endif