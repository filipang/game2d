#pragma once
#include "Animation.h"
#include "TextureManager.h"

class Entity
{
public:

	float x, y;

	std::string name;

	Animation* animation;
	moony::Sprite* sprite;
	moony::Texture* texture;

public:

	Entity(float x, float y, std::string animName, std::string animState);
	void update(float deltaTime);
	~Entity();
};

