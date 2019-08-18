#include "Animation.h"
#include "TextureManager.h"
#include "moony/Texture.h"
#include <iostream>

void Animation::update(float deltaTime) {
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= frame_count_map[state]) {
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

void Animation::setState(std::string state) {
	totalTime = 0;
	currentImage.x = 0;
	currentImage.y = state_y_map[state];
	this->state = state;
}

void Animation::loadAnimation(std::string animation) {
	
	//While the returned texture is not empty (width != 0)
	this->animation = TextureManager::getInstance()->getTextureByName(animation + ".png");
	uvRect = this->animation.m_rect;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = this->animation.m_rect.width / max_frame_count;
	uvRect.height = this->animation.m_rect.height / clip_count;
}

Animation::Animation()
{
}


Animation::~Animation()
{
}
