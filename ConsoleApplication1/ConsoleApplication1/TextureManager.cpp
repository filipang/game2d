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


void TextureManager::loadAtlas(std::string atl_name) {

	sf::Texture atlas;
	moony::TextureAtlas* texture_atlas = new moony::TextureAtlas();
	texture_atlas->loadFromFile("atlases/" + atl_name + ".mtpf");
	TextureManager::getInstance()->loadedAtlases[atl_name] = texture_atlas;
}

moony::Texture TextureManager::getTextureByName(std::string name) {
	return loadedAtlases[ResourceManager::getInstance()->texture_atlas_map[name]]->findSubTexture(name);
}

moony::Texture TextureManager::getTextureByName(std::string name, std::string atlas) {

	moony::Texture m_texture = loadedAtlases[atlas]->findSubTexture(name);

	return m_texture;
}

