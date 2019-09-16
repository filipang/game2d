#pragma once
#include <iostream>
#include "TextureManager.h"
#include "ResourceManager.h"
#include "SFML/Graphics.hpp"

TextureManager* TextureManager::instance = 0;
TextureManager* TextureManager::getInstance()
{

	if (!instance)
		instance = new TextureManager();

	return instance;
}

TextureManager::TextureManager(){}


void TextureManager::registerObj(IUnknown *obj)
{
	ITexture *toAdd = nullptr;
	if (obj->QueryInterface(ITexture::myType, (void**)&toAdd) == false)
		return;

	toAdd->AddRef();
	registeredList.insert(toAdd);
}

void TextureManager::unregisterObj(IUnknown *obj)
{
	ITexture *toRem = nullptr;
	if (obj->QueryInterface(ITexture::myType, (void**)&toRem) == false)
		return;

	registeredList.erase(toRem);
	toRem->Release();
}


moony::Texture TextureManager::getTextureByName(std::string name) {
	return ResourceManager::getInstance()->texture_atlas.findSubTexture(name);
}
