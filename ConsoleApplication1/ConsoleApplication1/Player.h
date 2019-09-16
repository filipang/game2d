#pragma once

class Player : public CoUnknown1<IInputReciever>, public Entity
{
public:

	void handleInput() override;

	Player(float x, float y, std::string animName, std::string defaultState, float speed);
	~Player();
};

