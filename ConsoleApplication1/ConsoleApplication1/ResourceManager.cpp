#include <fstream>
#include <iostream>
#include "ResourceManager.h"
#include "json/json.h"

ResourceManager* ResourceManager::instance = NULL;

ResourceManager* ResourceManager::getInstance()
{
	if (ResourceManager::instance == NULL) {
		ResourceManager::instance = new ResourceManager();
	}

	return ResourceManager::instance;
}

ResourceManager::ResourceManager()
{

	Json::Value json_data;
	Json::Reader reader;
	std::ifstream in("data.json");
	bool parsing_successful = reader.parse(in, json_data);
	if(!parsing_successful) {
		// report to the user the failure and their locations in the document.
		std::cout << "Failed to parse configuration\n" << reader.getFormatedErrorMessages();
		return;
	}
	try {
		std::vector<std::string> list = json_data.getMemberNames();
		Json::Value def;
		for (std::vector<std::string>::iterator i = list.begin(); i != list.end(); i++) {
			std::cout << *i << std::endl;
			ResourceManager::texture_atlas_map[*i] = json_data[*i].asString();
		
		}
	}
	catch (Json::LogicError error) {
		std::cout << "Exception: " << error.what() << std::endl;
	}

	Json::Reader reader2;
	Json::Value json_data2;
	std::ifstream in2("animation_map.json");
	bool parsing_successful2 = reader2.parse(in2, json_data2);
	if (!parsing_successful2) {
		// report to the user the failure and their locations in the document.
		std::cout << "Failed to parse configuration\n" << reader2.getFormatedErrorMessages();
		return;
	}
	try {
		std::vector<std::string> list = json_data2.getMemberNames();
		Json::Value def;
		for (std::vector<std::string>::iterator i = list.begin(); i != list.end(); i++) {
			std::cout << *i << std::endl;

			animation_atlas_map[*i].atlas		= json_data2[*i]["atlas"].asString();
			animation_atlas_map[*i].clip_count	= json_data2[*i]["clip_count"].asInt();
			animation_atlas_map[*i].max_frame_count = json_data2[*i]["max_frame_count"].asInt();
			for (int ind = 0; ind < animation_atlas_map[*i].clip_count; ind++) {
				std::cout << *(json_data2[*i]["clip_array"][ind].getMemberNames()).begin();
				animation_atlas_map[*i].clip_array.push_back(std::make_pair(*(json_data2[*i]["clip_array"][ind].getMemberNames()).begin(), ind));
			}

		}
	}
	catch (Json::LogicError error) {
		std::cout << "Exception: " << error.what() << std::endl;
	}
}


void ResourceManager::loadAtlas(std::string atl_name) {
	texture_atlas.loadFromFile("atlases/" + atl_name + ".mtpf");
}

