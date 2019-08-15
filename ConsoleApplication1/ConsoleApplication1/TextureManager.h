#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <tuple>

class TextureManager
{
public:
	static TextureManager* instance;

	std::map<std::string, sf::Texture> loadedAtlases;

public:
	static TextureManager* getInstance();

	TextureManager();

	void loadAtlas(std::string atl_name);

	std::pair<sf::Texture*, sf::IntRect> getTextureByName(std::string name);
};

