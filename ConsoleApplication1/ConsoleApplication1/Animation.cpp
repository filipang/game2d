#include "Animation.h"
#include "TextureManager.h"
#include "moony/Texture.h"
#include <iostream>
#include "ResourceManager.h"

void Animation::update(float deltaTime) {
	totalTime += deltaTime;
	std::cout << "SIZOFTEXTURE: " << sizeof(sprite->m_subtexture) << std::endl;
	//animation = &sprite->m_subtexture;
	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		

		sprite->m_subtexture.m_rect.left = sprite->m_subtexture.m_rect.left + sprite->m_subtexture.m_rect.width;
		//animation->m_rect.left = animation->m_rect.left + animation->m_rect.width;
		// currentImage.x * uvRect->width;
		//uvRect->top = currentImage.y * uvRect->height;
		//uvRect->left += 0.01f;
		currentImage.x++;
		std::cout << "gotta.." << totalTime << " AT THE FRAME " << currentImage.x << std::endl;
		if (currentImage.x >= max_frame_count) {
			currentImage.x = 0;
			sprite->m_subtexture.m_rect.left = reset;
		}
		//sprite->m_subtexture = *animation;
		//animation = &sprite->m_subtexture;

	}
}

void Animation::setState(std::string state) {
	totalTime = 0.0f;
	currentImage.x = 0;
	for(std::pair<std::string, int> st : ResourceManager::getInstance()->animation_atlas_map[animation_name].clip_array){
		if (st.first == state) {
			currentImage.y = st.second;
		}
	}
	currentImage.y = 0;
	this->state = state;
}

moony::Texture* Animation::loadAnimation(std::string animation, moony::Texture* texture, moony::Sprite* sprite) {
	animation_name	= animation;
	max_frame_count	= ResourceManager::getInstance()->animation_atlas_map[animation].max_frame_count;
	clip_count		= ResourceManager::getInstance()->animation_atlas_map[animation].clip_count;
	//While the returned texture is not empty (width != 0)
	this->sprite = sprite;

	//uvRect = &sprite->m_subtexture.m_rect;
	totalTime = 0.0f;
	currentImage.x = 0;
	sprite->m_subtexture.m_rect.width = sprite->m_subtexture.m_rect.width / max_frame_count;
	sprite->m_subtexture.m_rect.height = sprite->m_subtexture.m_rect.height / clip_count;
	//spriteWidth = this->animation->m_rect.width;
	//spriteHeight = this->animation->m_rect.height;
	reset = sprite->m_subtexture.m_rect.left;
	//std::cout << uvRect->width << std::endl;
	return &sprite->m_subtexture;
}

Animation::Animation()
{
}


Animation::~Animation()
{
}
