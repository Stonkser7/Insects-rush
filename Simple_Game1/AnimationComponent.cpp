#include "AnimationComponent.h"

void AnimationComponent::update(float elapsed_time)
{
	timer_ += elapsed_time;
	float duration = anim_->getFrame(current_frame_).getDuration();
	while (timer_ > duration) {
		timer_ -= duration;

		if (current_frame_ == anim_->numberOfFrames() - 1) {
			current_frame_ = 0;
		}
		else {
			++current_frame_;
		}
	}
}

void AnimationComponent::setAnim(Animation* new_anim, int current_frame)
{
	anim_ = new_anim;
	current_frame_ = current_frame;
}

void AnimationComponent::toSprite(sf::Sprite& target)
{
	const sf::Texture& t = anim_->getFrame(current_frame_).getTexture();

	target.setTextureRect(sf::IntRect(0, 0, t.getSize().x, t.getSize().y));
	target.setTexture(t);

	target.setOrigin(anim_->getFrame(current_frame_).getOrigin());
}
