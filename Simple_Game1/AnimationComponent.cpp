#include "AnimationComponent.h"

void AnimationComponent::update(sf::Sprite& sprite, float elapsed_time)
{

}

void AnimationComponent::setAnim(Animation* newAnim)
{
	anim_ = newAnim;
}
