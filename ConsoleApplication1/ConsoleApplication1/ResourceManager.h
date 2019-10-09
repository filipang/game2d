#pragma once
#include <map>
#include <tuple>
#include <fstream>
#include "moony/TextureAtlas.h"
#include "Resource.h"
#include <SFML/Graphics.hpp>

#define MAX_FILE_SIZE 100000
#define DEFAULT_MAP_SIZE_X 40
#define DEFAULT_MAP_SIZE_Y 20
#define F_READ(filestream,obj) filestream.read((char*)(&obj), sizeof(obj))
#define F_WRITE(filestream,obj) filestream.write((char*)(&obj), sizeof(obj)) 
#define PUSH(buffer, value)		auto temp = value; \
								memcpy(buffer , &temp, sizeof(temp))

#define POP(buffer, value)  memcpy(&value, buffer, sizeof(value))

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

	std::vector<Resource*> _atlasses;

	moony::TextureAtlas texture_atlas;

	std::map<std::string, std::string> texture_atlas_map;

	std::map<std::string, animation_entry> animation_atlas_map;

public:
	static ResourceManager* getInstance();

	bool loadLevelFromBuffer(unsigned char buffer[], int buffer_size);

	int loadLevelFileToBuffer(std::string level_name, unsigned char buffer[]);

	void loadAtlas(std::string atl_name);

	ResourceManager();
	
};

