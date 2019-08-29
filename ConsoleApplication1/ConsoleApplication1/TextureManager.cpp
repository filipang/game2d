#pragma once
#include <iostream>
#include "TextureManager.h"
#include "ResourceManager.h"
#include "SFML/Graphics.hpp"

TextureManager* TextureManager::instance = 0;
TextureManager* TextureManager::getInstance()
{

	if (!instance)
		instance = new TextureManager();

	return instance;
}

TextureManager::TextureManager(){}


moony::Texture TextureManager::getTextureByName(std::string name) {
	return ResourceManager::getInstance()->texture_atlas.findSubTexture(name);
}
