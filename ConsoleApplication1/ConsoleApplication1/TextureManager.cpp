#include "pch.h"
#include <iostream>
#include "TextureManager.h"
#include "SFML/Graphics.hpp"
#include "ResourceManager.h"

TextureManager* TextureManager::instance = NULL;

TextureManager* TextureManager::getInstance()
{
	if (TextureManager::instance == NULL) {
		TextureManager::instance = new TextureManager();
	}

	return TextureManager::instance;
}

TextureManager::TextureManager()
{
}


void TextureManager::loadAtlas(std::string atl_name) {
	sf::Texture atlas;
	atlas.loadFromFile("bob.jpg");
	TextureManager::loadedAtlases[atl_name] = atlas;
	//Function that compact all the textures that are supposed to be in the atl_name atlas
	//into the this atlas, and it appends it to loadedAtlases vector
}

std::pair<sf::Texture*, sf::IntRect> TextureManager::getTextureByName(std::string name) {

	std::cout <<	ResourceManager::getInstance()->texture_rect_map[name].first.x <<
					ResourceManager::getInstance()->texture_rect_map[name].first.y <<
					ResourceManager::getInstance()->texture_rect_map[name].second.x <<
					ResourceManager::getInstance()->texture_rect_map[name].second.y << 
					std::endl;


	sf::IntRect rect(ResourceManager::getInstance()->texture_rect_map[name].first.x, 
					 ResourceManager::getInstance()->texture_rect_map[name].first.y, 
					 ResourceManager::getInstance()->texture_rect_map[name].second.x,
					 ResourceManager::getInstance()->texture_rect_map[name].second.y);
	return std::make_pair(&loadedAtlases[ResourceManager::getInstance()->texture_atlas_map[name]], rect);
}
