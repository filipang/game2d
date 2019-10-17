#pragma once
#include <list>
#include "ResourceManager.h"
#include "IUnknown.h"
#include "Interfaces.h"
class Map : public CoUnknown1<ISerializable>
{
public:
	static const int clsid = CLS_Map;

public:
	struct save_tile {
		unsigned char occupation = 0;
		unsigned char no_tiles_occupying_this = 0;
		std::list<int> tile_id_vector;
	};

	struct save {
		int map_size_x;
		int map_size_y;
		save_tile** grid;
	};

public:
	Map();
	save scene;

	size_t popFromBuffer(unsigned char* buffer, size_t offset);
	size_t pushToBuffer(unsigned char* buffer, size_t offset);
	size_t getSizeInBytes();

	~Map();
};

