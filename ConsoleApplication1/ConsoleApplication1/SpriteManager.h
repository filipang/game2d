#pragma once
#include <SFML/Graphics.hpp>
#include "moony/Sprite.h"

class SpriteManager
{
public:
	static SpriteManager* instance;

public:
	static SpriteManager* getInstance();

	SpriteManager();

	moony::Sprite getSpriteByName(std::string sp_name);
};