#include "Entity.h"
#include "Animation.h"
#include <iostream>
#include "TextureManager.h"

/*void Entity::CreateEntity(std::string animName, std::string animState, Animation a)
{
	texture = TextureManager::getInstance()->getTextureByName(animName);
	moony::Sprite sprite(texture);
	std::cout << "lol" << sprite.getPosition().y << std::endl;
	sprite.setOrigin(a.spriteWidth / 2, a.spriteHeight / 2);
	a.loadAnimation(animName, &texture, &sprite);
	a.setState(animState);

}*/

Entity::Entity(float x, float y, std::string animName, std::string defaultState, float speed){

	faceRight = true;
	Entity::texture = new moony::Texture(TextureManager::getInstance()->getTextureByName("man.png"));
	Entity::sprite = new moony::Sprite(*texture);
	animation = new Animation();

	animation->switchTime = 0.04f;
	animation->loadAnimation(animName, texture, sprite);
	animation->setState(defaultState);
	animation->update(0.0f);
	sprite->setPosition(x, y);
	sprite->setOrigin(animation->spriteWidth / 2, animation->spriteHeight / 2);
	Entity::speed = speed;
}

void Entity::move(float deltaTime) {
	Entity::sprite->move(deltaTime*speed*norm_velocity, 0.0f);
}

void Entity::update(float deltaTime) {
	animation->update(deltaTime);
	move(deltaTime);
}


Entity::~Entity()
{
}
