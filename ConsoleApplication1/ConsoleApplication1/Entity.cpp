#include "Entity.h"
#include "Animation.h"
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

Entity::Entity(float x, float y, std::string animName, std::string animState)
{

	Entity::texture = new moony::Texture(TextureManager::getInstance()->getTextureByName("man.png"));
	Entity::sprite = new moony::Sprite(*texture);
	animation = new Animation();

	animation->switchTime = 0.0001f;
	animation->loadAnimation(animName, texture, sprite);
	animation->setState(animState);
	animation->update(0.0f);
	sprite->setPosition(x, 200.0f);
	std::cout << sprite->getPosition().y;
	sprite->setOrigin(animation->spriteWidth / 2, animation->spriteHeight / 2);
}

void Entity::update(float deltaTime) {
	Entity::animation->update(deltaTime);
}


Entity::~Entity()
{
}
