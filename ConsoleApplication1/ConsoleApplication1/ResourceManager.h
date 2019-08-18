#pragma once
#include <map>
#include <tuple>
#include <fstream>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
	static ResourceManager* instance;

	std::map<std::string, std::string> texture_atlas_map;
	std::map<std::string, std::string> animation_atlas_map;

public:
	static ResourceManager* getInstance();

	void loadAnimationMap() {
		
	}

	ResourceManager();

	
};

