#pragma once
#include "InputRegistrable.h"
#include "Entity.h"

class Player : public InputRegistrable, public Entity
{
public:

	void handleInput() override;

	Player(float x, float y, std::string animName, std::string defaultState, float speed);
	~Player();
};

