#pragma once
#include "Animation.h"
#include "TextureManager.h"

class Entity
{
public:

	float x, y;

	std::string name;


	moony::Sprite* spritePtr;
	moony::Texture* texturePtr;

	Animation* a;

public:

	Entity(float x, float y, std::string animName, std::string animState, moony::Texture* texturePtr, moony::Sprite* spritePtr, Animation* a);
	~Entity();
};

