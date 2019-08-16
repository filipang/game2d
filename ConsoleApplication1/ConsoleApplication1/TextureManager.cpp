#pragma once
#include <iostream>
#include "TextureManager.h"
#include "ResourceManager.h"
#include "SFML/Graphics.hpp"




TextureManager* TextureManager::instance = 0;
TextureManager* TextureManager::getInstance()
{
	if (!instance) {
		std::cout << "WAS NULL NOT NMROE" << std::endl;
		instance = new TextureManager();
	}
	else {
		std::cout << "NO NEED FOR" << std::endl;
	}

	return instance;
}

TextureManager::TextureManager()
{
}


void TextureManager::loadAtlas(std::string atl_name) {
	sf::Texture atlas;
	moony::TextureAtlas texture_atlas;
	texture_atlas.loadFromFile("atlases/" + atl_name + ".mtpf");
	TextureManager::getInstance()->loadedAtlases["moony_texture_packer_ready"] = &texture_atlas;
	TextureManager::getInstance()->loadedAtlases["moony_texture_packer_ready"]->findSubTexture("makepng.png");

	std::cout << "THERE ARE HEIGHT !!!..." << TextureManager::getInstance()->loadedAtlases["moony_texture_packer_ready"]->findSubTexture("makepng.png").m_rect.width << std::endl;
	//Function that compacts all the textures that are supposed to be in the atl_name atlas
	//into the this atlas, and it appends it to loadedAtlases vector
}

std::pair<const sf::Texture*, sf::Rect<int>> TextureManager::getTextureByName(std::string name) {

	//OLD WAY FOR ATLASING
	/*
	sf::IntRect rect(ResourceManager::getInstance()->texture_rect_map[name].first.x, 
					 ResourceManager::getInstance()->texture_rect_map[name].first.y, 
					 ResourceManager::getInstance()->texture_rect_map[name].second.x,
					 ResourceManager::getInstance()->texture_rect_map[name].second.y);
	*/
	std::cout << "THERE ARE..." << TextureManager::getInstance()->loadedAtlases.size()  << " + " << ResourceManager::getInstance()->texture_atlas_map[name] << std::endl;
	std::cout << "THERE ARE HEIGHT !!!..." << TextureManager::getInstance()->loadedAtlases["moony_texture_packer_ready"]->findSubTexture("makepng.png").m_rect.width << std::endl;
	std::cout << "THERE ARE..." << TextureManager::getInstance()->loadedAtlases["moony_texture_packer"]->getSubTextureNames().size() << std::endl;
	moony::Texture m_texture = loadedAtlases[ResourceManager::getInstance()->texture_atlas_map[name]]->findSubTexture("makepng.png");

	return std::make_pair(m_texture.m_texture, m_texture.m_rect);
}
