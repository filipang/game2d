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
	TextureManager::getInstance()->loadedAtlases["moony_texture_packer_ready"] = texture_atlas;
}

std::pair<const sf::Texture*, sf::Rect<int>> TextureManager::getTextureByName(std::string name) {

	const moony::Texture* m_texture; 
	m_texture = &loadedAtlases[ResourceManager::getInstance()->texture_atlas_map[name]]->findSubTexture(name);
	return std::make_pair(m_texture->m_texture, m_texture->m_rect);
}
