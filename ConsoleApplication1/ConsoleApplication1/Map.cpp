#include "Map.h"
#include "ResourceManager.h"


Map::Map()
{
}

/*
bool loadWorldFromFile(std::string file_name, Map::save& s) {
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
}*/

size_t Map::popFromBuffer(unsigned char * buffer, size_t offset)
{
	int size;
	POP(buffer + offset, size);
	offset -= sizeof(size);
	POP(buffer + offset, scene.map_size_x);
	offset -= sizeof(scene.map_size_x);
	POP(buffer + offset, scene.map_size_y);
	offset -= sizeof(scene.map_size_y);


	return 0;
}

size_t Map::pushToBuffer(unsigned char * buffer, size_t offset){
	PUSH(buffer + offset, clsid);
	offset += sizeof(clsid);
	PUSH(buffer + offset, getSizeInBytes());
	offset += sizeof(getSizeInBytes());
	return 0;
}

size_t Map::getSizeInBytes()
{
	return sizeof(clsid);
}

Map::~Map()
{
}
