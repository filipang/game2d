#pragma once

class Player : public CoUnknown2<IInputReciever, ISerializable>, public Entity
{
public:
	static const int clsid = CLS_Player;
public:
	void handleInput() override;

	size_t popFromBuffer(unsigned char* buffer, size_t offset) override;
	size_t pushToBuffer(unsigned char* buffer, size_t offset) override;
	size_t getSizeInBytes() override;

	Player(float x, float y, std::string animName, std::string defaultState, float speed);
	~Player();
};

