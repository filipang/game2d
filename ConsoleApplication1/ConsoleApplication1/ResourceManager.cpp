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
	ResourceManager::texture_atlas_map;
}

