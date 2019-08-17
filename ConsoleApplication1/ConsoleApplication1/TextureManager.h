#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <tuple>
#include "moony/TextureAtlas.h"

class TextureManager
{
private:
	static TextureManager* instance;
public:
	std::map<std::string, moony::TextureAtlas*> loadedAtlases;

public:
	static TextureManager* getInstance();

	TextureManager();

	void loadAtlas(std::string atl_name);

	moony::Texture getTextureByName(std::string name);
};
