#pragma once
#include <map>
#include <tuple>
#include <fstream>
#include "moony/TextureAtlas.h"
#include "Resource.h"
#include <SFML/Graphics.hpp>

#define DEFAULT_MAP_SIZE_X 40
#define DEFAULT_MAP_SIZE_Y 20
#define F_READ(filestream,obj) filestream.read((char*)(&obj), sizeof(obj))
#define F_WRITE(filestream,obj) filestream.write((char*)(&obj), sizeof(obj)) 

class ResourceManager
{
	struct animation_entry
	{
		std::string atlas;
		int clip_count;
		int max_frame_count;
		std::vector<std::pair<std::string, int>> clip_array;
	};

	struct save_tile {
		unsigned char occupation = 0;
		unsigned char no_tiles_occupying_this = 0;
		short tile_id_vector[5];
	};

	struct save {
		int MAP_SIZE_X = DEFAULT_MAP_SIZE_X;
		int MAP_SIZE_Y = DEFAULT_MAP_SIZE_Y;
		save_tile grid[DEFAULT_MAP_SIZE_X][DEFAULT_MAP_SIZE_Y];
	};


	bool loadWorldFromFile(std::string file_name, save& s) {
		std::ifstream file(file_name, std::ios::in | std::ios::binary);
		int size_x, size_y;
		F_READ(file, size_x);
		F_READ(file, size_y);
		for (int j = 0; j < size_y; j++) {
			for (int i = 0; i < size_x; i++) {
				F_READ(file, s.grid[i][j].occupation);
				F_READ(file, s.grid[i][j].no_tiles_occupying_this);
				for (int nav = 0; nav < s.grid[i][j].no_tiles_occupying_this; nav++) {
					F_READ(file, s.grid[i][j].tile_id_vector[nav]);
				}


			}
		}

		return true;
	}

public:
	static ResourceManager* instance;

	std::vector<Resource*> _atlasses;

	moony::TextureAtlas texture_atlas;

	std::map<std::string, std::string> texture_atlas_map;

	std::map<std::string, animation_entry> animation_atlas_map;

public:
	static ResourceManager* getInstance();

	void loadAtlas(std::string atl_name);

	ResourceManager();
	
};

