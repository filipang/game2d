#pragma once
#include <map>
#include <tuple>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
	static ResourceManager* instance;

	std::map<std::string, std::string> texture_atlas_map;

public:
	static ResourceManager* getInstance();

	ResourceManager();

	
};

