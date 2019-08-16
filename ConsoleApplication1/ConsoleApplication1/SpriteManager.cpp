#include "SpriteManager.h"
#include "TextureManager.h"

SpriteManager* SpriteManager::instance = NULL;

SpriteManager* SpriteManager::getInstance()
{
	if (SpriteManager::instance == NULL) {
		SpriteManager::instance = new SpriteManager();
	}
	return SpriteManager::instance;
}

SpriteManager::SpriteManager()
{
}


sf::Sprite SpriteManager::getSpriteByName(std::string sp_name) {
	std::pair<const sf::Texture*, sf::IntRect> ret = TextureManager::getInstance()->getTextureByName(sp_name);

	sf::Sprite sprite(*ret.first);
	sprite.setTextureRect(ret.second);
	return sf::Sprite(sprite);
}
