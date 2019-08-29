#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <tuple>
#include "moony/Texture.h"

class TextureManager
{
private:
	static TextureManager* instance;

public:
	static TextureManager* getInstance();

	TextureManager();

	moony::Texture getTextureByName(std::string name);
};
