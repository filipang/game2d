#pragma once
#include <map>
#include <tuple>
#include <fstream>
#include <SFML/Graphics.hpp>

class ResourceManager
{
	struct animation_entry
	{
		std::string atlas;
		int clip_count;
		int max_frame_count;
		std::vector<std::pair<std::string, int>> clip_array;
	};

public:
	static ResourceManager* instance;

	std::map<std::string, std::string> texture_atlas_map;
	std::map<std::string, animation_entry> animation_atlas_map;
public:
	static ResourceManager* getInstance();

	void loadAnimationMap() {
		
	}

	ResourceManager();

	
};

