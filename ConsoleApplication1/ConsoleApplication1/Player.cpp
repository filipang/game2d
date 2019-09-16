#include "Interfaces.h"
#include "Entity.h"
#include "Player.h"



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
}

Player::Player(float x, float y, std::string animName, std::string defaultState, float speed) : Entity(x, y, animName, defaultState, speed)
{

}


Player::~Player()
{
}
