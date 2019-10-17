#include "Interfaces.h"
#include "Entity.h"
#include "Player.h"
#include <iostream>




void Player::handleInput()
{
	norm_velocity = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		norm_velocity -= 1.0f;
		if (faceRight) {
			faceRight = false;
			sprite->setScale(-1.0f, 1.0f);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		norm_velocity += 1.0f;
		if (!faceRight) {
			faceRight = true;
			sprite->setScale(1.0f, 1.0f);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		std::cout << "PLAYER HAS THIS MANY REFS: " << this->GetRefCount() << std::endl;
	}
}


void Player::move(float deltaTime) {
	Player::sprite->move(deltaTime*speed*norm_velocity, 0.0f);
}

void Player::update(float deltaTime) {
	animation->update(deltaTime);
	move(deltaTime);
}

size_t Player::popFromBuffer(unsigned char * buffer, size_t offset)
{
	return size_t();
}

size_t Player::pushToBuffer(unsigned char * buffer, size_t offset)
{

	return 0;
}

size_t Player::getSizeInBytes()
{
	return size_t();
}

Player::Player(float x, float y, std::string animName, std::string defaultState, float speed) {

	faceRight = true;
	Player::texture = new moony::Texture(TextureManager::getInstance()->getTextureByName("man.png"));
	//Manager::getInstance()->registerObj(Entity::texture);
	Player::sprite = new moony::Sprite(*texture);
	//Manager::getInstance()->registerObj(Entity::sprite);
	animation = new Animation();

	animation->switchTime = 0.04f;
	animation->loadAnimation(animName, texture, sprite);
	animation->setState(defaultState);
	animation->update(0.0f);
	sprite->setPosition(x, y);
	sprite->setOrigin(animation->spriteWidth / 2, animation->spriteHeight / 2);
	Player::speed = speed;
}


Player::~Player()
{
}
