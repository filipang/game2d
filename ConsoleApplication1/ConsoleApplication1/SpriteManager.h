#pragma once
#include <SFML/Graphics.hpp>

class SpriteManager
{
public:
	static SpriteManager* instance;

public:
	static SpriteManager* getInstance();

	SpriteManager();

	sf::Sprite getSpriteByName(std::string sp_name);
};