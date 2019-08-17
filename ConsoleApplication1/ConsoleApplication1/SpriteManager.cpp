#include "SpriteManager.h"
#include "TextureManager.h"
#include "moony/Sprite.h"

SpriteManager* SpriteManager::instance = NULL;

SpriteManager* SpriteManager::getInstance()
{
	if (SpriteManager::instance == NULL) {
		SpriteManager::instance = new SpriteManager();
	}
	return SpriteManager::instance;
}

SpriteManager::SpriteManager(){}


moony::Sprite SpriteManager::getSpriteByName(std::string sp_name) {

	moony::Texture ret = TextureManager::getInstance()->getTextureByName(sp_name);
	moony::Sprite sprite(ret);
	return ret;
}
