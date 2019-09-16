#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SpriteManager.h"

SpriteManager* SpriteManager::instance = 0;

SpriteManager* SpriteManager::getInstance()
{
	if (SpriteManager::instance == NULL) {
		SpriteManager::instance = new SpriteManager();
	}
	return SpriteManager::instance;
}

SpriteManager::SpriteManager(){}


void SpriteManager::registerObj(IUnknown *obj)
{
	ISprite *toAdd = nullptr;
	if (obj->QueryInterface(ISprite::myType, (void**)&toAdd) == false)
		return;

	toAdd->AddRef();
	registeredList.insert(toAdd);
}

void SpriteManager::unregisterObj(IUnknown *obj)
{
	ISprite *toRem = nullptr;
	if (obj->QueryInterface(ISprite::myType, (void**)&toRem) == false)
		return;

	registeredList.erase(toRem);
	toRem->Release();
}

moony::Sprite SpriteManager::getSpriteByName(std::string sp_name) {

	moony::Texture ret = TextureManager::getInstance()->getTextureByName(sp_name);
	moony::Sprite sprite(ret);
	return ret;
}
