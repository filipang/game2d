#pragma once
#include "Animation.h"
#include "TextureManager.h"

class Entity : public CoUnknown1<ISerializable>
{
public:
	static const int clsid = CLS_Entity;
public:

	float x, y;
	float speed;
	float norm_velocity;
	bool faceRight;
	short id;

	std::string name;

	Animation* animation;
	moony::Sprite* sprite;
	moony::Texture* texture;

public:
	Entity();
	Entity(float x, float y, std::string animName, std::string defaultState, float speed);
	
	size_t popFromBuffer(unsigned char* buffer, size_t offset);
	size_t pushToBuffer(unsigned char* buffer, size_t offset);
	size_t getSizeInBytes();

	void move(float deltaTime);
	void update(float deltaTime);
	~Entity();
};

