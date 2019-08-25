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

Entity::Entity(float x, float y, std::string animName, std::string animState, moony::Texture* texturePtr, moony::Sprite* spritePtr, Animation* a)
{
	this->spritePtr = spritePtr;
	this->texturePtr = texturePtr;

	a->loadAnimation(animName, texturePtr, spritePtr);
	a->setState(animState);
	spritePtr->setPosition(x, 200.0f);
	printf("%d", spritePtr->getPosition().y);
	spritePtr->setOrigin(a->spriteWidth / 2, a->spriteHeight / 2);
}


Entity::~Entity()
{
}
