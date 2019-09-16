#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include "Interfaces.h"
#include "moony/Texture.h"

class TextureManager : public IRegisterUnk
{
private:
	static TextureManager* instance;

	std::set<ITexture*> registeredList;

public:
	static TextureManager* getInstance();

	TextureManager();

	virtual void registerObj(IUnknown* obj) override;

	virtual void unregisterObj(IUnknown *obj) override;

	moony::Texture getTextureByName(std::string name);
};
