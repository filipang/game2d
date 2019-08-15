#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "ResourceManager.h"

class SpriteManager
{
public:
	static SpriteManager* instance;

	TextureManager* txture_mgr;
	ResourceManager* res_mgr;

public:
	static SpriteManager* getInstance();

	SpriteManager();

	sf::Sprite getSpriteByName(std::string sp_name);
};