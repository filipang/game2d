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

Player::Player(float x, float y, std::string animName, std::string defaultState, float speed) : Entity(x, y, animName, defaultState, speed)
{

}


Player::~Player()
{
}
