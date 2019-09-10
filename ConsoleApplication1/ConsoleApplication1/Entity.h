#pragma once
#include "Animation.h"
#include "TextureManager.h"
#include "InputRegistrable.h"

class Entity
{
public:

	float x, y;
	float speed;
	float norm_velocity;
	bool faceRight;

	std::string name;

	Animation* animation;
	moony::Sprite* sprite;
	moony::Texture* texture;

public:

	Entity(float x, float y, std::string animName, std::string defaultState, float speed);
	void move(float deltaTime);
	void update(float deltaTime);
	~Entity();
};

