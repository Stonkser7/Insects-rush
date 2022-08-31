#include "AnimationComponent.h"

void AnimationComponent::update(float elapsed_time)
{
	timer_ += elapsed_time;
	while (timer_ > anim_->getFrame(current_frame_).getDuration()) {
		timer_ -= anim_->getFrame(current_frame_).getDuration();

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
	target.setTextureRect(sf::IntRect(0, 0, anim_->getFrame(current_frame_).getTexture().getSize().x, anim_->getFrame(current_frame_).getTexture().getSize().y));
	target.setTexture(anim_->getFrame(current_frame_).getTexture());
	target.setOrigin(anim_->getFrame(current_frame_).getOrigin());
}
