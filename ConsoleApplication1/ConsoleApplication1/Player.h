#pragma once

class Player : public CoUnknown2<IInputReciever, ISerializable>
{
public:
	static const int clsid = CLS_Player;
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
	void handleInput() override;

	size_t popFromBuffer(unsigned char* buffer, size_t offset) override;
	size_t pushToBuffer(unsigned char* buffer, size_t offset) override;
	size_t getSizeInBytes() override;

	void move(float deltaTime);
	void update(float deltaTime);

	Player(float x, float y, std::string animName, std::string defaultState, float speed);
	~Player();
};

